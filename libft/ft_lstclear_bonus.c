/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:17:02 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:17:04 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	while (list != NULL)
	{
		temp = list->next;
		ft_lstdelone(list, del);
		list = temp;
	}
	*lst = NULL;
}
