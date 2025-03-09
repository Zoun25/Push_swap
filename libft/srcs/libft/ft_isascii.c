/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:15:31 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 00:15:34 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
		return (0);
}

/*#include <unistd.h>
#include <ctype.h>

int	main(void)
{
	int	c;
	int	r;

	c = 65;
	r = ft_isascii(c);
	if (r == 0)
		write (1, "No es un ascii\n", 15);
	else
		write (1, "Es un ascii\n", 12);
	r = isdigit(c);
    if (r == 0)
        write (1, "No es un ascii\n", 15);
    else
        write (1, "Es un ascii\n", 12);
	return (0);
}*/
