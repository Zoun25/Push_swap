/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 05:13:22 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/04/20 05:13:23 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

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

/*returns val of the idx in the list if exist*/
int	ft_get_val_idx(t_stack *stack, char type, int val)
{
	int		i;
	t_list	*tmp;

	if (type == 'a')
		tmp = stack->a.first;
	else
		tmp = stack->b.first;
	i = 0;
	while (i <= val)
	{
		if (i == val)
			return ((int)(long)tmp->content);
		tmp = tmp->next;
		i++;
	}
	if (i == val)
		return ((int)(long)tmp->content);
	return (ft_push_error(87), 0);
}

int	ft_stack_sorted(t_stack *stack, char type)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (type == 'a')
		tmp_1 = stack->a.first;
	else
		tmp_1 = stack->b.first;
	while (tmp_1->next)
	{
		tmp_2 = tmp_1;
		while (tmp_2->content)
		{
			if ((int)(long)tmp_1->content > (int)(long)tmp_2->content)
				return (0);
			if (tmp_2-> next)
				tmp_2 = tmp_2->next;
			else
				break ;
		}
		tmp_1 = tmp_1->next;
	}
	return (1);
}
