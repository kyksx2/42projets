/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:31:46 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/09 17:44:21 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_small_three(t_list **stack_a, t_list **stack_b)
{
	int	pos;

	pos = find_smallest_pos(*stack_a);
	if (pos == 1)
		sa(stack_a);
	else if (pos == 2)
		rra(stack_a);
	pb(stack_a, stack_b);
}

void	push_small_four(t_list **stack_a, t_list **stack_b)
{
	int	pos;

	pos = find_smallest_pos(*stack_a);
	if (pos == 1)
		sa(stack_a);
	else if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (pos == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
}

void	push_small_five(t_list **stack_a, t_list **stack_b)
{
	int	pos;

	pos = find_smallest_pos(*stack_a);
	if (pos == 1)
		sa(stack_a);
	else if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (pos == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
}

int	find_smallest_pos(t_list *stack)
{
	int	min;
	int	pos;
	int	i;

	min = *(int *)stack->content;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (*(int *)stack->content < min)
		{
			min = *(int *)stack->content;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}
