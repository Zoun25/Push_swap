/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:42:23 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/11/09 19:42:26 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nbrsize(int n)
{
	int	l;

	l = 0;
	if (n == -2147483648)
		return (11);
	else
	{
		if (n < 0)
		{
			l++;
			n = -n;
		}
		while (n >= 10)
		{
			l++;
			n /= 10;
		}
	}
	l++;
	return (l);
}

static char	*ft_putnbr(int n, char *str, int i)
{
	int	a;
	int	b;

	a = ft_nbrsize(n) + i - 1;
	b = a + 1;
	while (i <= a)
	{
		str[a--] = (n % 10 + '0');
		n /= 10;
	}
	str[b] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_nbrsize(n) + 1));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str[i++] = '-';
		str[i++] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	str = ft_putnbr(n, str, i);
	return (str);
}
