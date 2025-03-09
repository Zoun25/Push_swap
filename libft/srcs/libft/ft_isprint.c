/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:22:27 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 00:22:29 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	r = ft_isprint(c);
	if (r == 0)
		write (1, "No es imprimible\n", 17);
	else
		write (1, "Es imprimible\n", 14);
	r = isalpha(c);
    if (r == 0)
        write (1, "No imprimible\n", 17);
    else
        write (1, "Es una letra\n", 14);
	return (0);
}*/