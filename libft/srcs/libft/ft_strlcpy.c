/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:06:53 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/14 07:06:56 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			l;
	size_t			conf;
	char			*temp1;
	char			*temp2;

	temp1 = dest;
	temp2 = (char *)src;
	conf = ft_strlen(src);
	l = 0;
	if (size != 0)
	{
		while (*temp2 != '\0' && l < size - 1)
		{
			*temp1 = *temp2;
			temp1++;
			temp2++;
			l++;
		}
		*temp1 = '\0';
	}
	return (conf);
}
