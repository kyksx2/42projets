/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:29:53 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/06 11:53:41 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*prev;

	if (ft_lstsize(*stack) < 2 || !stack || !*stack)
		exit(0);
	prev = NULL;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	last->next = *stack;
	prev->next = NULL;
	*stack = last;
}

void	rra(t_list **stack)
{
	reverse(stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack)
{
	reverse(stack);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putendl_fd("rrr", 1);
}
