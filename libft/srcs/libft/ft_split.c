/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:00 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/10/09 16:14:02 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	w;
	int	b;

	i = 0;
	w = 0;
	b = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			b = 1;
		}
		else if (s[i] != c && b == 1)
		{
			i++;
			w++;
			b = 0;
		}
		else
			i++;
	}
	return (w);
}

static int	ft_strlenc(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static void	ft_freestr(char **str, int i)
{
	int	l;

	l = 0;
	while (l < i)
	{
		free(str[l]);
		l++;
	}
	free(str);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		w;
	char	**str;

	i = 0;
	w = ft_countwords(s, c);
	str = (char **)malloc(sizeof(char *) * (w + 1));
	if (str == NULL)
		return (NULL);
	while (i < w && *s)
	{
		if (!ft_strlenc(s, c))
			s++;
		else
		{
			str[i] = (char *)malloc(sizeof(char) * ft_strlenc(s, c) + 1);
			if (str[i] == NULL)
				return (ft_freestr(str, i), NULL);
			ft_strlcpy((char *)str[i], s, (size_t)ft_strlenc(s, c) + 1);
			s = s + ft_strlenc(s, c);
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}
