/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:53:40 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/01 21:16:33 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_node(t_stack *a, t_stack *b)
{
	int	size_b;

	size_b = ft_sizelst(b);
	while (size_b--)
	{
		if (b->valor < a->valor)
		{
			if (a->target == NULL || a->target->valor < b->valor)
				a->target = b;
		}
		b = b->next;
	}
	if (a->target == NULL)
		a->target = ft_max(b);
}

void	ft_cal_costs(t_stack *head, t_stack *a, t_stack *b)
{
	a->cost[0] = ft_distance(a, head);
	a->cost[1] = ft_sizelst(head) - a->cost[0];
	a->target->cost[0] = ft_distance(a->target, b);
	a->target->cost[1] = ft_sizelst(b) - a->target->cost[0];
	a->dir = 0;
	a->t_cost = a->cost[0];
	if (a->cost[1] < a->cost[0])
	{
		a->t_cost = a->cost[1];
		a->dir = 1;
	}
	a->target->dir = 0;
	a->target->t_cost = a->target->cost[0];
	if (a->target->cost[1] < a->target->cost[0])
	{
		a->target->t_cost = a->target->cost[1];
		a->target->dir = 1;
	}
}

void	ft_calc_cost(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		size_a;
	int		i;

	size_a = ft_sizelst(a);
	i = 0;
	tmp = a;
	while (i < size_a)
	{
		ft_get_node(a, b);
		ft_cal_costs(tmp, a, b);
		i++;
		a = a->next;
	}
}
