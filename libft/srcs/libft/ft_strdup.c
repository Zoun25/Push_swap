/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 02:46:36 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/25 02:46:38 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	l1;

	l1 = ft_strlen(s1);
	s2 = (char *)malloc(l1 + 1);
	if (s2 == NULL)
		return (NULL);
	else
	{
		l1 = 0;
		while (s1[l1] != '\0')
		{
			s2[l1] = (char)s1[l1];
			l1++;
		}
		s2[l1] = '\0';
		return (s2);
	}
}
