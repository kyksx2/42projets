/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:28:07 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/06 11:53:49 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	if (!stack || !*stack)
		exit(0);
	first = *stack;
	second = first->next;
	tmp = *((int *)first->content);
	*((int *)first->content) = *((int *)second->content);
	*((int *)second->content) = tmp;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
