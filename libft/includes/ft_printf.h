/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:16:16 by ysadki-z          #+#    #+#             */
/*   Updated: 2024/03/19 19:16:18 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_print_c(int c);
int	ft_print_u(unsigned int n);
int	ft_print_di(int n);
int	ft_print_s(char *str);
int	ft_print_p(unsigned long long ptr);
int	ft_print_x(unsigned int n, const char letter);
int	ft_printf(const char *format, ...);

#endif
