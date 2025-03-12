/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:52:50 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/03 18:07:57 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		printf("%ld\n", *(long *)current->content);
		current = current->next;
	}
}
