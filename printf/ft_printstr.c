/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:06:26 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/28 13:25:28 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/*int	main(void)
{
	printf("\n%d\n", ft_printstr("je suis", 2));
}*/