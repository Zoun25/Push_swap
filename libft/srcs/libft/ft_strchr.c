/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:25:46 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 07:25:49 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (const char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (0);
}

/* #include <string.h>
#include <stdio.h>
int main()
{
	const char str1[] = "hola";
	int c = 97;
	char *str2 = ft_strchr(str1, c);
	printf("%s\n", str2);
	char *str3 = strchr(str1, c);
	printf("%s", str3);
	return (0);
} */