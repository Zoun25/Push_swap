/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:30:58 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/11 14:18:07 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
	r = ft_isalpha(c);
	if (r == 0)
		write (1, "No es una letra\n", 16);
	else
		write (1, "Es una letra\n", 13);
	r = isalpha(c);
    if (r == 0)
        write (1, "No es una letra\n", 16);
    else
        write (1, "Es una letra\n", 13);
	return (0);
}*/
