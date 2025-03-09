/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:26:54 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/27 15:27:32 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	char	*sub;

	a = ft_strlen(s1) + ft_strlen(s2);
	sub = (char *)malloc((sizeof(char)) * (a + 1));
	if (sub == NULL)
		return (NULL);
	a = 0;
	b = 0;
	while (s1[a] != '\0')
	{
		sub[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		sub[a] = s2[b];
		a++;
		b++;
	}
	sub[a] = '\0';
	return (sub);
}
