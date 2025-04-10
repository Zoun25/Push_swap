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


void	ft_sort_10(t_stack *stack, int index)
{
	while (stack->a.len > 3)
	{
		index = ft_get_min_index(stack, 'a');
		if (index == 1)
			ft_push_b(stack);
		else if (index < ((int)stack->a.len / 2))
			ft_rotate_a(stack);
		else
			ft_reverse_a(stack);
	}
	ft_five_cases(stack);
	while (stack->b.len > 0)
	{
		index = ft_get_max_index(stack, 'b');
		if (index == 1)
			ft_push_a(stack);
		else if (index < ((int)stack->b.len / 2))
			ft_rotate_b(stack);
		else
			ft_reverse_b(stack);
	}
}

void	ft_simple_sort(t_stack *stack, int *srt)
{
	if (stack->size == 2)
	{
		if (stack->knot[0] > stack->knot[1])
			ft_swap_a(stack);
	}
	else if (stack->size == 3)
	{
		if (ft_is_sorted(stack, srt))
			return ;
		ft_five_cases(stack);
	}
	else
		ft_sort_10(stack, 0);
}

void	ft_amoves(t_stack *stack, int *srt, int i, int cut)
{
	int	idx;
	int	rev;
	int	key;

	if (i == cut - 1)
		key = srt[stack->size - 1];
	else
		key = srt[(i + 1) * cut - 1];
	while (ft_find_first_lk(stack->a.first, key) != -1)
	{
		idx = ft_find_first_lk(stack->a.first, key);
		if (idx <= (int)stack->a.len / 2)
			while (idx-- > 0)
				ft_rotate_a(stack);
		else
		{
			rev = (int)stack->a.len - idx;
			while (rev-- > 0)
				ft_reverse_a(stack);
		}
		ft_push_b(stack);
	}
}


int	*ft_lis(t_stack *stack, int *lis_len)
{
	int	*dp;
	int	*prev;
	int	i;
	int	j;

	dp = malloc(sizeof(int *) * stack->size);
	prev = malloc(sizeof(int *) * stack->size);
	if (!dp || !prev)
		return (NULL);
	i = 0;
	while (i < (int)stack->size)
	{
		dp[i] = 1;
		prev[i++] = -1;
	}
	i = 1;
	while (i < (int)stack->size)
	{
		j = 0;
		while (j < i)
		{
			if (stack->knot[i] > stack->knot[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
	i = 0;
	int	max;
	while (i < (int)stack->size)
	{
		if (dp[i] > *lis_len)
		{
			*lis_len = dp[i];
			max = i;
		}
		i++;
	}
	int	*lis;
	lis = (int *)ft_calloc((int)stack->size, sizeof(int *));
	if (!lis)
		return (NULL);
	while (max != -1)
	{
		lis[max] = 1;
		max = prev[max];
	}
	return (free(dp), free(prev), lis);
}

void	ft_sort_100(t_stack *stack)
{
	int	lis_len;
	int	*lis;
	int	i;
	int	moves;
	int	idx;

	lis = ft_lis(stack, &lis_len);
	if (!lis)
		ft_push_error(1);
	i = 0;
	while (i < (int)stack->a.len)
	{
		if (ft_is_in_lis(stack->a.first, lis, lis_len))
			ft_rotate_a(stack);
		else
			ft_push_b(stack);
	}
	free(lis);
	int	max_int;
	int moves_a;
	int moves_b;
	int pos_moves_a;
	int pos_moves_b;

	max_int = INT_MAX;
	i = 0;
	while (stack->b.len > 0)
	{
		while (i < (int)stack->b.len)
		{
			moves = ft_comp_lis(stack, i, &pos_moves_a, &pos_moves_b);
			if (moves < max_int)
			{
				max_int = moves;
				idx = i;
				moves_a = pos_moves_a;
				moves_b = pos_moves_b;
			}
		}
		i = 0;
		if (idx <= (int)stack->b.len / 2)
			while (i++ < idx)
				ft_rotate_b(stack);
		else
			while (i++ < ((int)stack->b.len - idx))
				ft_reverse_b(stack);
		ft_exec_moves(stack, moves_a, moves_b);
		ft_push_a(stack);
	}
	int min_idx;

	min_idx = ft_get_min_index(stack, 'a');
	if (min_idx <= (int)stack->a.len / 2)
		while (min_idx-- > 0)
			ft_rotate_a(stack);
	else
		while (min_idx++ < (int)stack->a.len)
			ft_reverse_a(stack);
}

/* void	ft_sort_100(t_stack *stack, int *srt)
{
	int	i;
	int	cut;

	cut = stack->size / 4;
	i = 0;
	while (i < cut)
	{
		ft_amoves(stack, srt, i, cut);
		i++;
	}
	ft_simple_sort(stack, srt);
	while (stack->b.len > 0)
	{
		i = ft_get_max_index(stack, 'b');
		if (i <= (int)stack->b.len / 2)
			while (i-- > 0)
				ft_rotate_b(stack);
		else
			while (i++ < (int)stack->b.len)
				ft_reverse_b(stack);
		ft_push_a(stack);
	}
}
 */
/*
void	ft_sort_500(t_stack *stack)
{
}
 */