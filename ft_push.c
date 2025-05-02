/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:44:31 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/01 16:19:38 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_push_aux(t_stack **src, t_stack **dst)
// {
// 	if (!(*dst)->next)
// 	{
// 		(*dst)->prev = *src;
// 		(*dst)->next = *src;
// 		(*src)->next = *dst;
// 		(*src)->prev = *dst;
// 	}
// 	else
// 	{
// 		(*dst)->prev->next = *src;
// 		(*src)->prev = (*dst)->prev;
// 		(*dst)->prev = *src;
// 		(*src)->next = *dst;
// 		*dst = (*dst)->prev;
// 	}
// }

// void	ft_push(t_stack **src, t_stack **dst)
// {
// 	t_stack	*tmp;

// 	if ((*src) == NULL)
// 		return ;
// 	tmp = (*src)->next;
// 	(*src)->prev->next = (*src)->next;
// 	(*src)->next->prev = (*src)->prev;
// 	if ((*dst) == NULL)
// 	{
// 		*dst = *src;
// 		(*dst)->next = NULL;
// 		(*dst)->prev = NULL;
// 	}
// 	ft_push_aux(src, dst);
// 	*src = tmp;
// }

void	ft_push_node(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	tmp = *src;
	if ((*src)->next)
	{
		(*src)->next->prev = (*src)->prev;
		(*src)->prev->next = (*src)->next;
		if ((*src)->next == (*src)->prev)
		{
			(*src)->next->next = NULL;
			(*src)->next->prev = NULL;
		}
	}
	*src = (*src)->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_addstack(dst, tmp);
	if ((*dst)->prev)
		*dst = (*dst)->prev;
}

void	ft_push_a(t_stack **a, t_stack **b)
{
	ft_push_node(b, a);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	ft_push_node(a, b);
	write(1, "pb\n", 3);
}
