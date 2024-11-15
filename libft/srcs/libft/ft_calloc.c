/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:14:04 by ysadki-z          #+#    #+#             */
/*   Updated: 2023/09/24 22:14:12 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

void	*ft_calloc(size_t n_elem, size_t s_elem)
{
	void	*p;

	p = (void *)malloc(n_elem * s_elem);
	if (p == NULL)
		return (NULL);
	else
	{
		ft_bzero(p, (n_elem * s_elem));
		return (p);
	}
}
