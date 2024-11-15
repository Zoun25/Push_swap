/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:35:05 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 00:35:07 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *str, int c, size_t l)
{
	unsigned int	i;

	i = 0;
	while (i < l)
	{
		((char *)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
/* #include <string.h>
#include <stdio.h>
int main()
{
	int str1[] = {1, 2, 3, 4, 5, 6};
	int str2[] = {1, 2, 3, 4, 5, 6};
	int c = 29;
	int i = -1;
	ft_memset(str1, c, 5);
	printf("Mi memset: ");
	while(++i < 5)
		printf("%d, ", str1[i]);
	i = -1;
	memset(str2, c, 5);
	printf("\nEl memset: ");
	while(++i < 5)
		printf("%d, ", str2[i]);
	return (0);
} */
