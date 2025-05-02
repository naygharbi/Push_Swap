/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:20:57 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:21:02 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len_s2;

	if (*s2 == '\0')
		return ((char *)s1);
	len_s2 = ft_strlen(s2);
	while (*s1 != '\0' && n-- >= len_s2)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, len_s2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s1;
// 	const char	*s2;
// 	size_t		n;

// 	s1 = "Hola soy yo soy yo";
// 	s2 = "soy";
// 	n = 14;
// 	printf("%s\n", strnstr (s1, s2, n));
// 	return (0);
// }