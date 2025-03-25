/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:00:42 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/27 18:00:45 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

static int	ft_setfind(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if ((char)set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char		*sub;
	size_t		i;
	size_t		a;
	size_t		b;

	if (*s1 == '\0')
		return (ft_strdup(""));
	if (*set == '\0')
		return (ft_strdup(s1));
	a = 0;
	b = ft_strlen(s1) - 1;
	while (s1[a] && ft_setfind(s1[a], set))
		a++;
	while (b > a && ft_setfind((s1[b]), set))
		b--;
	if (a > b)
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (b - a + 2));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (a <= b)
		sub[i++] = s1[a++];
	sub[i] = '\0';
	return (sub);
}
/* int main()
{
	const char	s1[] = "";
	const char	set[] = "";
	const char	*sub;

	sub = ft_strtrim(s1, set);
	printf("%s", sub);
	return  (0);
} */
