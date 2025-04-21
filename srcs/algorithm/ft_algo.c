/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:32:09 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/04/02 12:32:10 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	ft_size_4(t_stack *stack)
{
	int	*s;

	s = stack->knot;
	if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3])
		ft_push_b(stack);
	else if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3])
	{
		ft_swap_a(stack, 0);
		ft_push_b(stack);
	}
	else if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3])
	{
		ft_rotate_a(stack, 0);
		ft_swap_a(stack, 0);
		ft_push_b(stack);
	}
	else if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3])
	{
		ft_reverse_a(stack, 0);
		ft_push_b(stack);
	}
	ft_five_cases(stack);
	ft_push_a(stack);
}

void	ft_simple_sort(t_stack *stack)
{
	if ((int)stack->a.len == 2 && stack->knot[0] > stack->knot[1])
		ft_swap_a(stack, 0);
	if ((int)stack->a.len == 3)
		ft_five_cases(stack);
	if ((int)stack->size == 4)
		ft_size_4(stack);
}

int	ft_rot_rest(t_stack *stack, int idx_a, int idx_b, int c)
{
	c = ft_rot_b(stack, idx_b, c);
	c = ft_rot_a(stack, idx_a, c);
	return (c);
}

void	ft_the_last_resort(t_stack *stack)
{
	int	lower_idx;

	lower_idx = ft_get_min_index(stack, 'a');
	if (lower_idx > ((int)stack->a.len / 2))
	{
		while (lower_idx++ < (int)stack->a.len)
			ft_reverse_a(stack, 0);
	}
	else
	{
		while (lower_idx-- > 0)
			ft_rotate_a(stack, 0);
	}
}

void	ft_sort(t_stack *stack)
{
	ft_push_b(stack);
	ft_push_b(stack);
	while (stack->a.len > 3 && !ft_stack_sorted(stack, 'a'))
		ft_b_sort(stack);
	ft_simple_sort(stack);
	while (stack->b.len > 0)
		ft_a_sort(stack);
	ft_the_last_resort(stack);
}
