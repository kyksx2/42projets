/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:54:08 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/06 17:26:04 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_error(char *s)
{
	ft_putendl_fd(s, 1);
	exit(1);
}

void	stack_free(t_list **stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
