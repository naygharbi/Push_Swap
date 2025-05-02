/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:02 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/02 13:33:06 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		s;
	long	num;
	int		i;

	s = 1;
	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * s);
}

int	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack))
		return (1);
	tmp = (*stack)->prev;
	while ((*stack) != tmp)
	{
		tmp2 = (*stack);
		(*stack) = (*stack)->next;
		tmp2->next = NULL;
		tmp2->prev = NULL;
		free(tmp2);
		tmp2 = NULL;
	}
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	free(*stack);
	return (1);
}

int	ft_sizelst(t_stack *lst)
{
	int		size;
	t_stack	*prev;

	size = 0;
	prev = NULL;
	if (lst)
		prev = lst->prev;
	while (lst != prev)
	{
		size++;
		lst = lst->next;
	}
	if (prev != NULL)
		size++;
	return (size);
}

t_stack	*ft_max(t_stack *a)
{
	t_stack	*max;
	int		lstsize;

	lstsize = ft_sizelst(a);
	max = a;
	while (lstsize--)
	{
		if (a->valor > max->valor)
			max = a;
		a = a->next;
	}
	return (max);
}

int	double_free(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (arr && *arr)
		free(*arr++);
	free(tmp);
	return (1);
}
