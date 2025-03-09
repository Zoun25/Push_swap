/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:25:49 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 00:25:53 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	const char str[] = "";

	i = ft_strlen(str);
	printf("mi funcion: %d\n", i);
	i = strlen(str);
	printf("funcion real : %d\n", i);
}
*/