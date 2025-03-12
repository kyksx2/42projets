/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:47:05 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/07 09:41:50 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	hard_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		min;

	tmp = *stack_a;
	min = get_min_value(stack_a);
	while (tmp)
	{
		*(int *)tmp->content -= min;
		tmp = tmp->next;
	}
	radix(stack_a, stack_b);
	tmp2 = *stack_a;
	while (tmp2)
	{
		*(int *)tmp2->content += min;
		tmp2 = tmp2->next;
	}
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;
	int	num;

	max_bits = get_max_bits(stack_a);
	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size && *stack_a && !is_sorted(stack_a))
		{
			num = *(int *)(*stack_a)->content;
			if (((num >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

/*int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = *(int *)head->content;
	max_bits = 0;
	while (head)
	{
		if (*(int *)head->content > max)
			max = *(int *)head->content;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	hard_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	num;

	max_bits = get_max_bits(stack_a);
	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size && *stack_a)
		{
			num = *(int *)(*stack_a)->content;
			if (((num >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while ((*stack_b))
			pa(stack_a, stack_b);
	i++;
	}
}*/