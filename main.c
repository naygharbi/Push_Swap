/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:22:17 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/02 13:54:20 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	if (check_non_numbers(argv) == -1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	else if (check_repeat(argv) == -1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	else if (check_limits(argv) == -1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

int	rotate_a(t_stack **a)
{
	t_stack	*min;
	int		dist;
	int		lstsize;

	min = ft_min(*a);
	dist = ft_distance(min, *a);
	lstsize = ft_sizelst(*a);
	if (dist < lstsize - dist)
		while (*a != min)
			ft_rev_a(a);
	else
		while (*a != min)
			ft_rotate_a(a);
	return (1);
}

void	ft_get_target(t_stack *b, t_stack *a)
{
	int	size_a;

	size_a = ft_sizelst(a);
	while (size_a--)
	{
		if (a->valor > b->valor)
		{
			if (b->target == NULL || b->target->valor > a->valor)
				b->target = a;
		}
		a = a->next;
	}
	if (b->target == NULL)
		b->target = ft_min(a);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (ft_issorted(a) && rotate_a(&a))
		return ;
	if (ft_sizelst(a) > 3)
		ft_push_b(&a, &b);
	if (ft_sizelst(a) > 3)
		ft_push_b(&a, &b);
	while (ft_sizelst(a) > 3)
	{
		ft_reset(a, b);
		ft_calc_cost(a, b);
		ft_execute(&a, &b);
	}
	sort_three(&a);
	while (b)
	{
		ft_reset(a, b);
		ft_get_target(b, a);
		rot_target(b->target, &a);
		ft_push_a(&a, &b);
	}
	rotate_a(&a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split;
	char	**tmp;

	a = NULL;
	b = NULL;
	split = NULL;
	tmp = argv + 1;
	if (argc >= 2)
	{
		split = ft_split(argv[1], ' ');
		if (split[1])
			tmp = split;
		if (check_args(tmp) == -1)
			return (0);
		a = stack_init(a, tmp);
		sort_stack(a, b);
		free_stack(&a);
		double_free(split);
	}
	return (0);
}
