/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:23:35 by ysadki-z          #+#    #+#             */
/*   Updated: 2024/03/19 19:23:37 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_s(char *str)
{
	int	size;

	size = 0;
	if (str == NULL)
		return (ft_print_s("(null)"));
	while (str[size])
	{
		if ((ft_print_c(str[size])) == -1)
			return (-1);
		size++;
	}
	return (size);
}

int	ft_print_di(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_c('0');
	else if (n == -2147483648 && size != -1)
	{
		size += ft_print_s("-2147483648");
	}
	else if (n < 0 && size != -1)
	{
		size += ft_print_c('-');
		n = -n;
	}
	if (n > 0 && size != -1)
		size += ft_print_u((unsigned int)n);
	if (size == -1)
		return (-1);
	return (size);
}

int	ft_print_u(unsigned int n)
{
	int	size;
	int	fix;

	size = 0;
	fix = 0;
	if (n == 0)
		size += ft_print_c('0');
	else
	{
		if (n / 10 != 0)
			ft_print_u(n / 10);
		fix += ft_print_c((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	if (size == -1 || fix == -1)
		return (-1);
	return (size);
}
