/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:13:03 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 07:13:08 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		l;
	size_t		ldest;
	size_t		lsrc;

	ldest = 0;
	lsrc = 0;
	l = 0;
	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	while (*dest)
		dest++;
	if (size == 0 || size <= ldest)
		return (lsrc + size);
	while (l < size - ldest - 1 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		l++;
	}
	*dest = '\0';
	return (lsrc + ldest);
}
