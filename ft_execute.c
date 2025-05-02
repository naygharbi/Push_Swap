/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:52:45 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/02 13:29:35 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_one(t_stack **node, int cost, int dir, int mode)
{
	if (mode == 1)
	{
		while (cost > 0)
		{
			if (dir == 0)
				ft_rev_a(node);
			else if (dir == 1)
				ft_rotate_a(node);
			cost = cost - 1;
		}
	}
	else if (mode == 2)
	{
		while (cost > 0)
		{
			if (dir == 0)
				ft_rev_b(node);
			else if (dir == 1)
				ft_rotate_b(node);
			cost = cost - 1;
		}
	}
}

void	ft_move_nodes(t_stack **a, t_stack *node, t_stack **b)
{
	while (node->t_cost > 0 && node->target->t_cost > 0)
	{
		if (node->dir == 0 && node->target->dir == 0)
			ft_rev_two(a, b);
		else if (node->dir == 1 && node->target->dir == 1)
			ft_rot_two(a, b);
		else
			break ;
		node->t_cost = node->t_cost - 1;
		(node->target->t_cost)--;
	}
	ft_move_one(a, node->t_cost, node->dir, 1);
	ft_move_one(b, node->target->t_cost, node->target->dir, 2);
	ft_push_b(a, b);
}

int	get_lower_opt(t_stack *a)
{
	int	options[4];
	int	i;
	int	min;

	options[0] = a->cost[0] + a->target->cost[1];
	options[1] = a->cost[1] + a->target->cost[0];
	options[2] = a->cost[0];
	options[3] = a->cost[1];
	if (a->cost[0] < a->target->cost[0])
		options[2] = a->target->cost[0];
	if (a->cost[1] < a->target->cost[1])
		options[3] = a->target->cost[1];
	i = 0;
	min = options[0];
	while (i < 4)
		if (options[i++] < min)
			min = options[i - 1];
	return (min);
}

void	ft_execute(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*tmp;
	int		size;
	int		t_cost;
	int		i;

	i = 0;
	size = ft_sizelst(*a);
	min = *a;
	tmp = *a;
	t_cost = get_lower_opt(tmp);
	while (i < size)
	{
		if (get_lower_opt(tmp) < t_cost)
		{
			t_cost = get_lower_opt(tmp);
			min = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	ft_move_nodes(a, min, b);
}
