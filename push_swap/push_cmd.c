/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:59:32 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/06 11:53:37 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*tmp1;

	if (!stack_src || !*stack_src)
		return ;
	tmp1 = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_lstadd_front(stack_dst, tmp1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
