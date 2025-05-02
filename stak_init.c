/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stak_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:51:46 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/02 13:33:58 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->valor = 0;
	stack->id = 0;
	stack->t_cost = __INT_MAX__;
	stack->dir = -1;
	stack->target = NULL;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stack	*ft_addstack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if ((*stack) == NULL)
	{
		(*stack) = new;
		return (new);
	}
	last = (*stack)->prev;
	(*stack)->prev = new;
	new->next = (*stack);
	new->prev = last;
	if (last == NULL)
	{
		new->prev = (*stack);
		(*stack)->next = new;
	}
	else
		last->next = new;
	return ((*stack));
}

t_stack	*stack_init(t_stack *a, char **argv)
{
	int		i;
	int		valor;
	t_stack	*tmp;

	i = 0;
	valor = 0;
	a = NULL;
	while (argv[i] != NULL)
	{
		tmp = ft_new_stack();
		valor = ft_atoi(argv[i]);
		tmp->valor = valor;
		tmp->id = i;
		tmp->t_cost = __INT_MAX__;
		tmp->dir = -1;
		tmp->target = NULL;
		ft_addstack(&a, tmp);
		i++;
	}
	return (a);
}
