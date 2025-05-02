/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:21:17 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:21:19 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	search_init(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && char_in_set(s[i], set))
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

int	search_end(char const *s, char const *set)
{
	int	i;

	if (s[0] == '\0')
		return (-1);
	i = ft_strlen(s) - 1;
	while (i > 0 && char_in_set(s[i], set))
		i--;
	if (i == 0)
		return (-1);
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		init;
	int		end;
	char	*copy;

	if (!s1 || !set)
		return (NULL);
	init = search_init(s1, set);
	end = search_end(s1, set);
	copy = (char *)malloc(sizeof(char) * (end - init + 1));
	if (copy == NULL)
		return (NULL);
	i = init;
	j = 0;
	while (i < end)
	{
		copy[j] = s1[i];
		i++;
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
