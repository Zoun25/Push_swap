/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:24:02 by ysadki-z          #+#    #+#             */
/*   Updated: 2024/03/19 19:24:03 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_hexl(unsigned int n)
{
	int	l;

	l = 0;
	while (n != 0)
	{
		l++;
		n = n / 16;
	}
	return (l);
}

int	ft_is_hex(unsigned int n, const char letter)
{
	int	fix;

	fix = 0;
	if (n >= 16)
	{
		ft_is_hex(n / 16, letter);
		ft_is_hex(n % 16, letter);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else if (fix != -1)
		{
			if (letter == 'x' && fix != -1)
				ft_print_c(n - 10 + 'a');
			if (letter == 'X' && fix != -1)
				ft_print_c(n - 10 + 'A');
		}
		else
			return (-1);
	}
	if (fix == -1)
		return (-1);
	return (0);
}

int	ft_print_x(unsigned int n, const char letter)
{
	if (n == 0)
		return (ft_print_c('0'));
	else if (ft_is_hex(n, letter) != -1)
		return (ft_hexl(n));
	else
		return (-1);
}
