/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_cont.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:41:30 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/03/31 15:41:44 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

void	ft_lstfree_cont(t_cont *cont)
{
	t_list	*tmp;

	while (cont->first)
	{
		tmp = cont->first->next;
		free(cont->first);
		cont->first = tmp;
	}
	cont->len = 0;
}
