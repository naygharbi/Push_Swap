/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:26:23 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/02 13:30:03 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_min(t_stack *a)
{
	t_stack	*min;
	int		lstsize;

	lstsize = ft_sizelst(a);
	min = a;
	while (lstsize--)
	{
		if (a->valor < min->valor)
			min = a;
		a = a->next;
	}
	return (min);
}

int	ft_issorted(t_stack *a)
{
	t_stack	*min;
	int		lstsize;

	if (!a)
		return (0);
	lstsize = ft_sizelst(a);
	min = ft_min(a);
	while (--lstsize)
	{
		if (min->valor > min->next->valor)
			return (0);
		min = min->next;
	}
	return (1);
}
