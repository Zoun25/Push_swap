/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 05:14:12 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/04/20 05:14:12 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	ft_rot_b(t_stack *stack, int idx_b, int c)
{
	if (idx_b <= ((int)stack->b.len / 2))
	{
		while (c > 0 && idx_b-- > 0)
		{
			c--;
			ft_rotate_b(stack, 0);
		}
	}
	else
	{
		while (c > 0 && idx_b++ < (int)stack->b.len)
		{
			c--;
			ft_reverse_b(stack, 0);
		}
	}
	return (c);
}

int	ft_get_cost(t_stack *stack, int *index_a)
{
	int	cost;
	int	lcost;
	int	idx_a;
	int	low_idx;
	int	max_idx;

	idx_a = 0;
	lcost = 2147483647;
	while (idx_a < (int)stack->a.len)
	{
		max_idx = ft_get_max_index(stack, 'b');
		low_idx = ft_find_close_b(stack,
				ft_get_val_idx(stack, 'a', idx_a));
		if (low_idx == -1)
			cost = ft_cal_cost(stack, idx_a, max_idx);
		else
			cost = ft_cal_cost(stack, idx_a, low_idx);
		if (lcost > cost)
		{
			lcost = cost;
			*index_a = idx_a;
		}
		idx_a++;
	}
	return (lcost);
}

int	ft_b_idx(t_stack *stack, int index_a)
{
	int	low;
	int	max;

	low = ft_find_close_b(stack, ft_get_val_idx(stack, 'a', index_a));
	max = ft_get_max_index(stack, 'b');
	if (low == -1)
		return (max);
	else
		return (low);
}

/*stack lower cost index and try to sort in a way b can sort more easily*/
void	ft_b_sort(t_stack *stack)
{
	int	index_a;
	int	index_b;
	int	cost;

	index_a = 0;
	cost = ft_get_cost(stack, &index_a);
	if (cost == 2147483647)
		ft_push_error(87);
	index_b = ft_b_idx(stack, index_a);
	if (cost == 0 && index_a == 0 && index_b == 0)
		ft_push_b(stack);
	else
	{
		if (ft_rotation_dir(stack, index_a, index_b) == 1)
			cost = ft_rotation(stack, &index_a, &index_b, cost);
		else if (ft_rotation_dir(stack, index_a, index_b) == -1)
			cost = ft_rev_rotation(stack, &index_a, &index_b, cost);
		if (cost > 0)
			cost = ft_rot_rest(stack, index_a, index_b, cost);
		if (cost == 0)
			ft_push_b(stack);
		else
			ft_push_error(87);
	}
}
