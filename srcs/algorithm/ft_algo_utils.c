/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:36:31 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/04/02 13:36:32 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	ft_get_min_index(t_stack *stack)
{
	int	min_index;
	int	i;

	i = 0;
	min_index = stack->knot[i];
	while (stack->knot[i] && i < (int)stack->size)
	{
		if (stack->knot[i] < min_index)
			min_index = stack->knot[i];
		i++;
	}
	return (min_index);
}

int	*ft_getsorted(t_stack *stack)
{
	int		*sorted_array;
	int		i;
	int		b;
	int		tmp;

	i = 0;
	b = 1;
	sorted_array = (int *)malloc(sizeof(int *) * stack->size);
	while (stack->knot[i] && i < (int)stack->size)
	{
		sorted_array[i] = stack->knot[i];
		i++;
	}
	while (b)
	{
		b = 0;
		i = 0;
		while (i < (int)stack->size - 1)
		{
			if (sorted_array[i] > sorted_array[i + 1])
			{
				tmp = sorted_array[i];
				sorted_array[i] = sorted_array[i + 1];
				sorted_array[i + 1] = tmp;
				b = 1;
			}
			i++;
		}
	}
	return (sorted_array);
}

int	ft_is_sorted(t_stack *stack, int *srt)
{
	int		i;
	int		size;
	t_list	*tmp;


	tmp = stack->a.first;
	size = (int)stack->size - 1;
	i = 0;
	while (tmp->content && srt[i] == (int)(long)tmp->content && i < size)
	{
		i++;
		tmp = tmp->next;
		if (i == size)
			return (1);
	}
	return (0);
}
