/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:52:47 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/03/31 20:52:48 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	ft_reverse_a(t_stack *stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack->a.first || stack->a.len < 2)
		ft_push_error(87);
	prev = stack->a.first;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack->a.first;
	stack->a.first = last;
	ft_printf("rra\n");
}

void	ft_reverse_b(t_stack *stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack->b.first || stack->b.len < 2)
		ft_push_error(87);
	prev = stack->b.first;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack->b.first;
	stack->b.first = last;
	ft_printf("rrb\n");
}

void	ft_reverse(t_stack *stack)
{

	if (!stack->a.first || stack->a.len < 2)
		ft_push_error(87);
	if (!stack->b.first || stack->b.len < 2)
		ft_push_error(87);
	ft_reverse_a(stack);
	ft_reverse_b(stack);
	ft_printf("rrr\n");
}
