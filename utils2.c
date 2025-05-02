/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:25:23 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/02 13:54:25 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_sizelst(a);
	while (size--)
	{
		a->t_cost = __INT_MAX__;
		a->dir = -1;
		a->target = NULL;
		a = a->next;
	}
	size = ft_sizelst(b);
	while (size--)
	{
		b->t_cost = __INT_MAX__;
		b->dir = -1;
		b->target = NULL;
		b = b->next;
	}
}

int	ft_distance(t_stack *min, t_stack *a)
{
	int	count;

	count = 0;
	while (a != min)
	{
		count++;
		min = min->next;
	}
	return (count);
}
