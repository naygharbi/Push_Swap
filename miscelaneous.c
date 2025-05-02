/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscelaneous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:53:25 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/01 16:59:04 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	two;
	int	three;

	two = (*a)->next->valor;
	three = (*a)->prev->valor;
	if ((*a)->valor > two && two > three)
	{
		ft_swap_a(a);
		ft_rev_a(a);
	}
	else if ((*a)->valor < three && two > three)
	{
		ft_rev_a(a);
		ft_swap_a(a);
	}
	else if ((*a)->valor > two && three > (*a)->valor)
		ft_swap_a(a);
	else if ((*a)->valor < two && (*a)->valor > three)
		ft_rev_a(a);
	else if ((*a)->valor > two && (*a)->valor > three)
		ft_rotate_a(a);
}

void	rot_target(t_stack *target, t_stack **a)
{
	int		dist;
	int		lstsize;

	dist = ft_distance(target, *a);
	lstsize = ft_sizelst(*a);
	if (dist < lstsize - dist)
		while (*a != target)
			ft_rev_a(a);
	else
		while (*a != target)
			ft_rotate_a(a);
}
