/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:19:19 by najlghar          #+#    #+#             */
/*   Updated: 2025/03/29 17:12:21 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s1, char set)
{
	int	count;

	count = 0;
	while (*s1)
	{
		if (*s1 != set)
		{
			count++;
			while (*s1 != 0 && *s1 != set)
				s1++;
		}
		else
			s1++;
	}
	return (count);
}

void	*freeall(char **array)
{
	int	counter;

	counter = 0;
	while (array[counter])
	{
		free(array[counter]);
		counter++;
	}
	free(array);
	return (NULL);
}

void	extravar(int *i, int *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		start;
	int		i;
	int		j;

	extravar(&i, &j, &start);
	array = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (array == 0 || !s)
		return (free(array), NULL);
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && start != -1)
		{
			array[j] = ft_substr(s, start, (i - start));
			if (!array[j])
				return (freeall(array));
			start = -1;
			j++;
		}
		i++;
	}
	return (array[j] = 0, array);
}
