/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:22:51 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/28 13:24:49 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(const char *str);
int		ft_printnbr(int n);
int		ft_printunsi(unsigned int n);
int		ft_printptr(void *ptr);
int		ft_printhex(unsigned int n, const char arg);

#endif