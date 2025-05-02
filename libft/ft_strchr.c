/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:19:26 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:19:28 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * buscar el caracter dentro de la cadena
 * 
 */

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (unsigned char)c)
			return ((char *)(string + i));
		i++;
	}
	if (string[i] == (unsigned char)c)
		return ((char *)(string + i));
	return (NULL);
}
