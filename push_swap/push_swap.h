/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:11:59 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/09 17:42:17 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

/***** check ************************/
int		check_args(int argc, char **argv);
int		correct_input(char **args);
int		is_signe(char c);
int		is_zero(char *args);
int		has_dupliacte(char **args);
int		args_cmp(const char *s1, const char *s2);
int		arg_is_number(char *argv);
/*************************************/
/***** utils *************************/
void	print_error(char *s);
void	ft_free(char **str);
long	ft_atol(const char *str);
void	stack_free(t_list **stack);
void	print_stack(t_list **stack_a);
/*************************************/
/***** commandes *********************/
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
/***************************************/
/***** tri *****************************/
void	sort_stack(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	hard_sort(t_list **stack_a, t_list **stack_b);
int		get_max_bits(t_list **stack);
int		get_min_value(t_list **stack_a);
void	radix(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b, int size);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	push_small_three(t_list **stack_a, t_list **stack_b);
void	push_small_four(t_list **stack_a, t_list **stack_b);
void	push_small_five(t_list **stack_a, t_list **stack_b);
int		find_smallest_pos(t_list *stack);
void	sort_five(t_list **stack_a, t_list **stack_b);

#endif