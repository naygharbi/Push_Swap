/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:41:29 by najlghar          #+#    #+#             */
/*   Updated: 2025/03/18 16:04:07 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg_pointer(char *argument)
{
	int	i;

	i = 0;
	if (argument[i] == '-' || argument[i] == '+')
		i++;
	if (argument[i] == '\0')
		return (-1);
	while (argument[i] != '\0')
	{
		if (ft_isdigit(argument[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_non_numbers(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (check_arg_pointer(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	compare_args(char **argv, int i)
{
	int	n1;
	int	n2;

	n1 = ft_atoi(argv[i]);
	i++;
	while (argv[i] != NULL)
	{
		n2 = ft_atoi(argv[i]);
		if (n1 == n2)
			return (-1);
		i++;
	}
	return (0);
}

int	check_repeat(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (compare_args(argv, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	check_limits(char **argv)
{
	long	value;
	int		i;

	i = 0;
	while (argv[i] != NULL)
	{
		value = ft_atol(argv[i]);
		if (value > +2147483647 || value < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}
