/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:56:22 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/04/21 02:56:23 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

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
