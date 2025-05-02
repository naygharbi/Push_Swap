/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:35:21 by najlghar          #+#    #+#             */
/*   Updated: 2025/05/02 13:58:01 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

// Define the data structure
typedef struct s_stack
{
	int				id;
	int				valor;
	int				cost[2];
	int				t_cost;
	int				dir;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// PARSEO
int		check_limits(char **argv);
int		check_repeat(char **argv);
int		compare_args(char **argv, int i);
int		check_non_numbers(char **argv);

t_stack	*stack_init(t_stack *a, char **argv);

// MOVIMIENTOS
void	ft_swap( t_stack **a);
void	ft_rotate_a(t_stack **a);
void	ft_rotate_b(t_stack **a);
void	ft_rot_two(t_stack **a, t_stack **b);
void	ft_swap_a(t_stack **a);
void	ft_swap_b(t_stack **a);
void	ft_swap_two(t_stack **a, t_stack **b);
void	ft_rev_a(t_stack **a);
void	ft_rev_b(t_stack **a);
void	ft_rev_two(t_stack **a, t_stack **b);
void	ft_push_a(t_stack **a, t_stack **b);
void	ft_push_b(t_stack **a, t_stack **b);
t_stack	*ft_addstack(t_stack **stack, t_stack *new);
t_stack	*ft_min(t_stack *a);
t_stack	*ft_max(t_stack *a);

// ALGORITMO
void	ft_calc_cost(t_stack *a, t_stack *b);
void	ft_execute(t_stack **a, t_stack **b);

// UTILS
long	ft_atol(const char *str);
int		free_stack(t_stack **stack);
int		ft_issorted(t_stack *a);
int		ft_sizelst(t_stack *lst);
int		ft_distance(t_stack *min, t_stack *a);
int		double_free(char **arr);
void	rot_target(t_stack *target, t_stack **a);
void	sort_three(t_stack **a);
int		ft_distance(t_stack *min, t_stack *a);
void	ft_reset(t_stack *a, t_stack *b);

#endif