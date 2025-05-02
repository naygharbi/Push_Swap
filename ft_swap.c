/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:43:03 by najlghar          #+#    #+#             */
/*   Updated: 2025/04/02 20:47:01 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap( t_stack **a)
{
	t_stack	*temp1;

	if (a == NULL || (*a)->next == NULL)
		return ;
	if ((*a)->next == (*a)->prev)
	{
		*a = (*a)->prev;
		return ;
	}
	temp1 = (*a)->prev;
	(*a)->prev->next = (*a)->next;
	(*a)->next->next->prev = *a;
	(*a)->prev = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a)->prev->prev = temp1;
	(*a)->prev->next = *a;
	*a = (*a)->prev;
}

void	ft_swap_a(t_stack **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **a)
{
	ft_swap(a);
	write(1, "sb\n", 3);
}

void	ft_swap_two(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
