/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:01:11 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 13:01:14 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	l;

	l = ft_strlen(str);
	if (c == '\0')
	{
		str += l;
		return ((char *)str);
	}
	while (l >= 0)
	{
		if (str[l] == (const char)c)
		{
			str += l;
			return ((char *)str);
		}
		l--;
	}
	return (0);
}
/* #include <string.h>
#include <stdio.h>
int main()
{
	const char str1[] = "hola";
	int c = 0;
	char *str2 = ft_strrchr(str1, c);
	printf("%s\n", str2);
	char *str3 = strrchr(str1, c);
	printf("%s", str3);
	return (0);
} */
