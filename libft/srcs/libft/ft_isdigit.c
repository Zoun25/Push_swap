/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:19:00 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/11 14:19:05 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
	r = ft_isdigit(c);
	if (r == 0)
		write (1, "No es un digito\n", 16);
	else
		write (1, "Es un digito\n", 13);
	r = isdigit(c);
    if (r == 0)
        write (1, "No es un digito\n", 16);
    else
        write (1, "Es un digito\n", 13);
	return (0);
}*/