/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:09:23 by yozai             #+#    #+#             */
/*   Updated: 2025/01/22 13:09:25 by yozai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	void	*tmp;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		tmp = (*lst)->content;
		(*lst)->content = new->content;
		new->content = tmp;
		new->next = *lst;
	}
}
