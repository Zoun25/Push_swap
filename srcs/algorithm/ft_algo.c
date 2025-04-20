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

int	ft_moves(t_stack *stack, int idx, char type)
{
	int	moves_up;
	int	moves_down;
	int	len;

	if (type == 'a')
		len = (int)stack->a.len;
	else
		len = (int)stack->b.len;
	moves_down = idx;
	moves_up = idx - len;
	if (ft_abs(moves_up) > ft_abs(moves_down))
		return (moves_down);
	else
		return (moves_up);

}

int	ft_cal_cost(t_stack *stack, int idx_a, int idx_b)
{
	int	a_moves;
	int	b_moves;
	int	cost;

	a_moves = ft_moves(stack, idx_a, 'a');
	b_moves = ft_moves(stack, idx_b, 'b');
	if (a_moves == 0 && b_moves == 0)
		return (0);
	if ((a_moves < 0 && b_moves < 0) || (a_moves > 0 && b_moves > 0))
	{
		cost = ft_abs(a_moves);
		if (ft_abs(b_moves) > cost)
			cost = ft_abs(b_moves);
	}
	else
		cost = ft_abs(a_moves) + ft_abs(b_moves);
	return (cost);
}

int	ft_rotation_dir(t_stack *stack, int idx_a, int idx_b)
{
	int	a_moves;
	int	b_moves;

	a_moves = ft_moves(stack, idx_a, 'a');
	b_moves = ft_moves(stack, idx_b, 'b');
	if (a_moves > 0 && b_moves > 0)
		return (1);
	if (a_moves < 0 && b_moves < 0)
		return (-1);
	return (0);
}

int	ft_rev_rotation(t_stack *stack, int *idx_a, int *idx_b, int c)
{
	while (*idx_a < (int)stack->a.len && *idx_b < (int)stack->b.len)
	{
		ft_reverse(stack);
		*idx_a += 1;
		*idx_b += 1;
		c--;
	}
	return (c);
}

int	ft_rotation(t_stack *stack, int *idx_a, int *idx_b, int c)
{
	while (*idx_a > 0 && *idx_b > 0)
	{
		ft_rotate(stack);
		*idx_a -= 1;
		*idx_b -= 1;
		c--;
	}
	return (c);
}

int	ft_rot_rest(t_stack *stack, int idx_a, int idx_b, int c)
{
	if (idx_a == 0)
		c = ft_rot_a(stack, idx_b, c);
	else
		c = ft_rot_a(stack, idx_a, c);
	return (c);
}

int	ft_rot_rest_a(t_stack *stack, int idx_a, int idx_b, int c)
{
	if (idx_b == 0)
		c = ft_rot_a(stack, idx_b, c);
	else
		c = ft_rot_b(stack, idx_a, c);
	return (c);
}

void	ft_sort_100(t_stack *stack)
{
	ft_push_b(stack);
	ft_push_b(stack);
	while (stack->a.len > 3 && !ft_stack_sorted(stack, 'a'))
		ft_b_sort(stack);
	ft_simple_sort(stack);
	ft_print_stacks(stack);
	while (stack->b.len > 0)
		ft_a_sort(stack);
}
