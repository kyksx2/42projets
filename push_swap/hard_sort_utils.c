/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:08:34 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/06 18:21:27 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		min;
	int		max_bits;

	head = *stack;
	max = *(int *)head->content;
	min = *(int *)head->content;
	max_bits = 0;
	while (head)
	{
		if (*(int *)head->content > max)
			max = *(int *)head->content;
		if (*(int *)head->content < min)
			min = *(int *)head->content;
		head = head->next;
	}
	max = max - min;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	get_min_value(t_list **stack_a)
{
	t_list	*tmp;
	int		min;

	tmp = *stack_a;
	min = *(int *)(tmp)->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}
