/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:53:02 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/03/31 20:53:04 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	ft_rotate_a(t_stack *stack)
{
	t_list	*node;

	if (!stack->a.first || stack->a.len < 2)
	{
		ft_lstfree(stack);
		ft_push_error(87);
	}
	node = stack->a.first;
	stack->a.first = node->next;
	node->next = NULL;
	ft_lstadd_back(&stack->a.first, node);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack *stack)
{
	t_list	*node;

	if (!stack->b.first || stack->b.len < 2)
	{
		ft_lstfree(stack);
		ft_push_error(87);
	}
	node = stack->b.first;
	stack->b.first = node->next;
	node->next = NULL;
	ft_lstadd_back(&stack->b.first, node);
	ft_printf("ra\n");
}

void	ft_rotate(t_stack *stack)
{
	if (!stack->a.first || stack->a.len < 2)
	{
		ft_lstfree(stack);
		ft_push_error(87);
	}
	if (!stack->b.first || stack->b.len < 2)
	{
		ft_lstfree(stack);
		ft_push_error(87);
	}
	ft_rotate_a(stack);
	ft_rotate_b(stack);
	ft_printf("rr\n");
}
