/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:23:20 by ysadki-z          #+#    #+#             */
/*   Updated: 2024/03/19 19:23:22 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_c(int c)
{
	if ((write(1, &c, 1)) == 1)
		return (1);
	else
		return (-1);
}

int	ft_print_type(va_list arg, const char letter)
{
	int	size;

	size = 0;
	if (letter == 'c')
		size += ft_print_c(va_arg(arg, int));
	else if (letter == 's')
		size += ft_print_s(va_arg(arg, char *));
	else if (letter == 'p')
		size += ft_print_p(va_arg(arg, unsigned long long));
	else if (letter == 'd' || letter == 'i')
		size += ft_print_di(va_arg(arg, int));
	else if (letter == 'u')
		size += ft_print_u(va_arg(arg, unsigned int));
	else if (letter == 'x' || letter == 'X')
		size += ft_print_x(va_arg(arg, unsigned int), letter);
	else
		size += ft_print_c(letter);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	arg;

	size = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			size += ft_print_type(arg, *(format + 1));
			if (size == -1)
				return (-1);
			format += 2;
		}
		else
		{
			if (ft_print_c(*format) == -1)
				return (-1);
			size++;
			format++;
		}
	}
	va_end(arg);
	return (size);
}
