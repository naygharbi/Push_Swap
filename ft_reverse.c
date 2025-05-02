/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:28:09 by najlghar          #+#    #+#             */
/*   Updated: 2025/04/02 20:48:48 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack **lst)
{
	if ((*lst) == NULL || (*lst)->prev == NULL)
		return ;
	(*lst) = (*lst)->prev;
}

void	ft_rev_a(t_stack **a)
{
	ft_reverse(a);
	write(1, "rra\n", 4);
}

void	ft_rev_b(t_stack **a)
{
	ft_reverse(a);
	write(1, "rrb\n", 4);
}

void	ft_rev_two(t_stack **a, t_stack **b)
{
	ft_reverse(a);
	ft_reverse(b);
	write(1, "rrr\n", 4);
}
