/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 05:13:58 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/04/20 05:13:59 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	ft_rot_a(t_stack *stack, int idx_a, int c)
{
	if (idx_a <= ((int)stack->a.len / 2))
	{
		while (c > 0 && idx_a-- > 0)
		{
			c--;
			ft_rotate_a(stack, 0);
		}
	}
	else
	{
		while (c > 0 && idx_a++ < (int)stack->a.len)
		{
			c--;
			ft_reverse_a(stack, 0);
		}
	}
	return (c);
}

int	ft_get_negative_cost(t_stack *stack, int *index_b)
{
	int	cost;
	int	lcost;
	int	idx_b;
	int	sup_idx;
	int	min_idx;

	idx_b = 0;
	lcost = 2147483647;
	while (idx_b < (int)stack->b.len)
	{
		min_idx = ft_get_min_index(stack, 'a');
		sup_idx = ft_find_close_a(stack,
				ft_get_val_idx(stack, 'b', idx_b));
		if (sup_idx == -1)
			cost = ft_cal_cost(stack, min_idx, idx_b);
		else
			cost = ft_cal_cost(stack, sup_idx, idx_b);
		if (lcost > cost)
		{
			lcost = cost;
			*index_b = idx_b;
		}
		idx_b++;
	}
	return (lcost);
}

int	ft_a_idx(t_stack *stack, int index_b)
{
	int	sup;
	int	min;

	sup = ft_find_close_a(stack, ft_get_val_idx(stack, 'b', index_b));
	min = ft_get_min_index(stack, 'a');
	if (sup == -1)
		return (min);
	else
		return (sup);
}

int	ft_negative_dir(t_stack *stack, int idx_a, int idx_b)
{
	int	a_moves;
	int	b_moves;

	a_moves = ft_moves(stack, idx_a, 'a');
	b_moves = ft_moves(stack, idx_b, 'b');
	if (a_moves < 0 && b_moves < 0)
		return (1);
	if (a_moves > 0 && b_moves > 0)
		return (-1);
	return (0);
}

void	ft_a_sort(t_stack *stack)
{
	int	index_a;
	int	index_b;
	int	cost;

	index_b = 0;
	cost = ft_get_negative_cost(stack, &index_b);
	if (cost == 2147483647)
		ft_push_error(87);
	index_a = ft_a_idx(stack, index_b);
	if (cost == 0 && index_a == 0 && index_b == 0)
		ft_push_a(stack);
	else
	{
		if (ft_negative_dir(stack, index_a, index_b) == -1)
			cost = ft_rotation(stack, &index_b, &index_a, cost);
		else if (ft_negative_dir(stack, index_a, index_b) == 1)
			cost = ft_rev_rotation(stack, &index_b, &index_a, cost);
		if (cost > 0)
			cost = ft_rot_rest(stack, index_a, index_b, cost);
		if (cost == 0)
			ft_push_a(stack);
		else
			ft_push_error(87);
	}
}
