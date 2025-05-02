/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:18:04 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:18:06 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_c;

	i = 0;
	ptr_c = (unsigned char *)s;
	while (i < n)
	{
		if (ptr_c[i] == (unsigned char)c)
		{
			ptr_c = (void *)&ptr_c[i];
			return (ptr_c);
		}
		i++;
	}
	ptr_c = NULL;
	return ((void *)ptr_c);
}
