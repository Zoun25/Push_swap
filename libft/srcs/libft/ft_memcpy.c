/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:42:13 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 02:42:18 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t l)
{
	unsigned int	i;
	char			*aux1;
	char			*aux2;

	i = 0;
	aux1 = (char *)dest;
	aux2 = (char *)src;
	if (aux1 == aux2 || l == 0)
		return (dest);
	while (i < l)
	{
		*aux1 = *aux2;
		i++;
		aux1++;
		aux2++;
	}
	return (dest);
}
/* #include <string.h>
#include <stdio.h>
int main()
{
	char dest1[] = "";
	char dest2[] = "";
	const char src[] = "";
	printf("src: %s", src);
	printf("\ndest antes: %s", dest1);
	ft_memcpy(dest1, src, 3);
	printf("\nmi dest despues: %s", dest1);
	memcpy(dest2, src, 3);
	printf("\nsu dest despues: %s\n", dest2);
	return (0);
} */
/* #include <string.h>
#include <stdio.h>
int main()
{
	int dest1[] = {22, 42, 32, 12, 8, 4};
	int dest2[] = {22, 42, 32, 12, 8, 4};
	const int src[] = {1, 2, 3, 4, 5, 6};
	int i = -1;
	ft_memcpy(dest1, src, 5);
	printf("Mi memcpy: ");
	while(++i < 5)
		printf("%d, ", dest1[i]);
	i = -1;
	memcpy(dest2, src, 5);
	printf("\nEl memcpy: ");
	while(++i < 5)
		printf("%d, ", dest2[i]);
	return (0);
} */