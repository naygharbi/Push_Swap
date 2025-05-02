/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:28:09 by najlghar          #+#    #+#             */
/*   Updated: 2025/04/02 20:43:23 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **lst)
{
	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	(*lst) = (*lst)->next;
}

void	ft_rotate_a(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **a)
{
	ft_rotate(a);
	write(1, "rb\n", 3);
}

void	ft_rot_two(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
