/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:54:07 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/11 15:16:35 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 3)
		sort_three(stack_a);
	if (size == 4)
		sort_four(stack_a, stack_b);
	if (size == 5)
		sort_five(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_small_five(stack_a, stack_b);
	push_small_four(stack_a, stack_b);
	push_small_three(stack_a, stack_b);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	push_small_four(stack_a, stack_b);
	push_small_three(stack_a, stack_b);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_three(t_list **stack_a)
{
	long	a;
	long	b;
	long	c;

	a = *((long *)((*stack_a)->content));
	b = *((long *)((*stack_a)->next->content));
	c = *((long *)((*stack_a)->next->next->content));
	if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && a > c && c > b)
		ra(stack_a);
	else if (b > a && b > c && a > c)
		rra(stack_a);
	else if (a > b && c > a && c > b)
		sa(stack_a);
	else if (b > a && b > c && c > a)
	{
		sa(stack_a);
		ra(stack_a);
	}
}
