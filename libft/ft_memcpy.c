/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:18:23 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:18:24 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*destiny;
	const char	*source;

	i = 0;
	destiny = dst;
	source = src;
	while (i < n && (src != NULL || dst != NULL))
	{
		destiny[i] = source[i];
		i++;
	}
	return (dst);
}
