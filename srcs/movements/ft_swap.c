/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:53:19 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/03/31 20:53:20 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	ft_swap_a(t_stack *stack)
{
	t_list	*tmp;

	if (stack->a.len < 2)
		ft_push_error(87);
	tmp = stack->a.first;
	stack->a.first = tmp->next;
	tmp->next = stack->a.first->next;
	stack->a.first->next = tmp;
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack *stack)
{
	t_list	*tmp;

	if (stack->b.len < 2)
		ft_push_error(87);
	tmp = stack->b.first;
	stack->b.first = tmp->next;
	tmp->next = stack->b.first->next;
	stack->b.first->next = tmp;
	ft_printf("sb\n");
}

void	ft_swap_ss(t_stack *stack)
{
	if (stack->a.len < 2 || stack->b.len < 2)
		ft_push_error(87);
	ft_swap_a(stack);
	ft_swap_b(stack);
	ft_printf("ss\n");
}
