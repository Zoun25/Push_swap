/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:53:00 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 15:53:02 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t l)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (to_find[a] == '\0')
		return ((char *)str);
	while (str[a] != '\0' && a < l)
	{
		if (str[a] == to_find[b])
		{
			while (str[a + b] == to_find[b] && (a + b) < l)
			{
				if (to_find [b + 1] == '\0')
					return ((char *)str + a);
				b++;
			}
			b = 0;
		}
		a++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int	main()
{
	char	str1[] = "aaabcabcd";
	char	str2[] = "abcd";
	char	*str3 = ft_strnstr(str1, str2, -1);
	char	*str4 = strnstr(str1, str2, -1);
	printf ("%s\n", str3);
	printf ("%s\n", str4);
	return (0);
} */
