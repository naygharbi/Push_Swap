/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:14:33 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:14:36 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i++] = 0;
	}
	return (p);
}
/*
int	main() {
	char	str[] = "Hello World";
	char	*ptr;
	int		i;

	ptr = ft_bzero(str, 5);
	i = 0;
	while (i < 10)
	{
		printf("%i\n", ptr[i++]);
	}
	return (0);
}
*/
/*
void	*ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return (s);
}
*/