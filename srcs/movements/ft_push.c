/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:45:45 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/03/31 20:45:47 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	ft_push_b(t_stack *stack)
{
	t_list	*node;

	if (!stack->a.first)
	{
		ft_lstfree(stack);
		ft_push_error(87);
	}
	node = stack->a.first;
	stack->a.first = node->next;
	node->next = NULL;
	if (!stack->b.first)
	{
		stack->b.first = node;
		stack->b.first->next = NULL;
	}
	else
	{
		node->next = stack->b.first;
		stack->b.first = node;
	}
	stack->b.len++;
	stack->a.len--;
	ft_printf("pb\n");
}

void	ft_push_a(t_stack *stack)
{
	t_list	*node;

	if (!stack->b.first)
	{
		ft_lstfree(stack);
		ft_push_error(87);
	}
	node = stack->b.first;
	stack->b.first = node->next;
	node->next = NULL;
	if (!stack->a.first)
	{
		stack->a.first = node;
		stack->a.first->next = NULL;
	}
	else
	{
		node->next = stack->a.first;
		stack->a.first = node;
	}
	stack->a.len++;
	stack->b.len--;
	ft_printf("pa\n");
}
