/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:07:56 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 00:08:04 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
	r = ft_isalnum(c);
	if (r == 0)
		write (1, "No es un digito o una letra\n", 28);
	else
		write (1, "Es un digito o una letra\n", 25);
	r = isdigit(c);
    if (r == 0)
        write (1, "No es un digito o una letra\n", 28);
    else
        write (1, "Es un digito o una letra\n", 25);
	return (0);
}*/
