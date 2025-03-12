/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:28:01 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/23 11:56:46 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	*gen_content(char *str)
{
	long	*tmp;

	tmp = (long *)ft_calloc(1, sizeof(long));
	if (!tmp)
		return (NULL);
	*tmp = ft_atol(str);
	return (tmp);
}

static void	compl_stack(t_list **stack_a, char **args)
{
	int		i;
	long	*content;
	t_list	*head;

	i = 0;
	while (args[i])
	{
		content = gen_content(args[i]);
		if (!content)
			return ;
		head = ft_lstnew((void *)content);
		if (!head)
			return ;
		ft_lstadd_back(stack_a, head);
		i++;
	}
}

static void	fill_stack(t_list **stack_a, int argc, char **argv)
{
	int		i;
	char	**args;

	i = 1;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		i = 0;
	}
	else
		args = argv;
	compl_stack(stack_a, &args[i]);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		exit (EXIT_FAILURE);
	if (!check_args(argc, argv))
		print_error("Erreur");
	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&stack_a, argc, argv);
	sort_stack(&stack_a, &stack_b);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
