/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:07:04 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 02:08:55 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_bzero(void *str, size_t l)
{
	ft_memset(str, 0, l);
	return (str);
}

/* #include <strings.h>
int main()
{
	char str[] = "Buenas tardes";
	ft_bzero(str, 3);
	return (0);
} */