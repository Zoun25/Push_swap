/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:46:27 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 15:46:29 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	l;

	l = 0;
	while (*s1 == *s2 && l < n)
	{
		l++;
		if (*s1 == *s2 && l == n)
			return (0);
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/* #include <stdio.h>
#include <string.h>
int main()
{
	char	str1[] = "abcdef";
	char	str2[] = "abc\375 xx";
	unsigned int	n = 5;
	int	ene;
	ene = ft_strncmp(str1, str2, n);
	printf("%d\n", ene);
	ene = strncmp(str1, str2, n);
	printf("%d\n", ene);
	printf("%s", str2);
	return (0);
} */
