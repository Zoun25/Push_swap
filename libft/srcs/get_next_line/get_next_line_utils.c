/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:47:39 by ysadki-z          #+#    #+#             */
/*   Updated: 2024/03/07 10:47:40 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (str == NULL || !str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (const char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (const char)c)
		return ((char *)str);
	else
		return (NULL);
}

void	*ft_calloc_gnl(size_t n_elem, size_t s_elem)
{
	void			*p;
	unsigned int	i;

	p = (void *)malloc(n_elem * s_elem);
	if (p == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < (n_elem * s_elem))
		{
			((char *)p)[i] = (unsigned char)0;
			i++;
		}
		return (p);
	}
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	i = ft_strlen_gnl(s);
	if (i <= start)
		return (ft_calloc_gnl(1, sizeof(char)));
	if (len > i - start)
		len = i - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	a;
	size_t	b;
	char	*sub;

	if (!s2)
		return (NULL);
	sub = ft_calloc_gnl(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1, 1);
	if (sub == NULL)
		return (NULL);
	a = 0;
	b = 0;
	if (s1)
	{
		while (s1[a])
		{
			sub[a] = s1[a];
			a++;
		}
		free(s1);
	}
	while (s2[b])
		sub[a++] = s2[b++];
	return (sub);
}
