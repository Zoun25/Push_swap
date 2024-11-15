/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:22:54 by ysadki-z          #+#    #+#             */
/*   Updated: 2024/03/19 19:23:02 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_ptrl(unsigned long long ptr)
{
	int	l;

	l = 0;
	while (ptr > 0)
	{
		l++;
		ptr /= 16;
	}
	return (l);
}

int	ft_is_ptr(unsigned long long ptr)
{
	int	fix;

	fix = 0;
	if (ptr >= 16)
	{
		ft_is_ptr(ptr / 16);
		ft_is_ptr(ptr % 16);
	}
	else
	{
		if (ptr < 10 && fix != -1)
			fix = ft_print_c(ptr + '0');
		else if (fix != -1)
			fix = ft_print_c(ptr - 10 + 'a');
		if (fix == -1)
			return (-1);
	}
	if (fix == -1)
		return (-1);
	return (0);
}

int	ft_print_p(unsigned long long ptr)
{
	int	size;
	int	fix;

	size = 0;
	fix = 0;
	size += ft_print_s("0x");
	if (ptr == 0)
	{
		if ((ft_print_c('0')) == -1)
			return (-1);
		size++;
	}
	else
	{
		fix = ft_is_ptr(ptr);
		size += ft_ptrl(ptr);
	}
	if (fix == -1)
		return (-1);
	else
		return (size);
}
