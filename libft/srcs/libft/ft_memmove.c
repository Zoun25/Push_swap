/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 04:29:55 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 04:30:29 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t l)
{
	if (dest < src)
		return (ft_memcpy(dest, src, l));
	if (l == 0 || dest == src)
		return (dest);
	while (l--)
		((char *)dest)[l] = ((char *)src)[l];
	return (dest);
}
/* #include <string.h>
#include <stdio.h>
int main()
{
	char dest1[] = "lorem ipum dolor sit a";
	char dest2[] = "lorem ipum dolor sit a";
	const char src[] = "lorem ipsum dolor sit amet";
	int l = strlen(src);
	printf("src: %s", src);
	printf("\ndest antes: %s", dest1);
	ft_memmove(dest1, src, 8);
	printf("\nmi dest despues: %s", dest1);
	memmove(dest2, src, 8);
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
	ft_memmove(dest1, src, 5);
	printf("Mi memmove: ");
	while(++i < 5)
		printf("%d, ", dest1[i]);
	i = -1;
	memmove(dest2, src, 5);
	printf("\nEl memmove: ");
	while(++i < 5)
		printf("%d, ", dest2[i]);
	return (0);
} */