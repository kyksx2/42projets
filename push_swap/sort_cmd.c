/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:02:40 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/08 12:42:19 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current && current->next)
	{
		if (*(long *)current->content > *(long *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (!stack_a || !*stack_a)
		exit(1);
	if (!(is_sorted(stack_a)))
	{
		if (size == 2)
			sa(stack_a);
		else if (size >= 3 && size <= 5)
			simple_sort(stack_a, stack_b, size);
		else
			hard_sort(stack_a, stack_b);
	}
	else
		return ;
}
