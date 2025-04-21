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

int	ft_get_min_index(t_stack *stack, char type)
{
	int		min_index;
	t_list	*tmp;

	if (type == 'a')
		tmp = stack->a.first;
	else
		tmp = stack->b.first;
	min_index = 0;
	while ((int)(long)tmp->content != ft_get_min_num(stack, type))
	{
		tmp = tmp->next;
		min_index++;
	}
	return (min_index);
}

int	ft_get_max_index(t_stack *stack, char type)
{
	int		max_index;
	t_list	*tmp;

	if (type == 'a')
		tmp = stack->a.first;
	else
		tmp = stack->b.first;
	max_index = 0;
	while ((int)(long)tmp->content != ft_get_max_num(stack, type))
	{
		tmp = tmp->next;
		max_index++;
	}
	return (max_index);
}

int	ft_get_case(t_stack *stack, int min_index, int max_index)
{
	t_list	*tmp;
	int		index;

	tmp = stack->a.first;
	index = (int)(long)tmp->content;
	if (index == min_index && (int)(long)tmp->next->next->content == max_index)
		return (0);
	if (index == min_index)
		return (1);
	else if (index == max_index)
	{
		if ((int)(long)tmp->next->content == min_index)
			return (2);
		else
			return (3);
	}
	else
	{
		if ((int)(long)tmp->next->content == min_index)
			return (4);
		else
			return (5);
	}
}

void	ft_five_cases(t_stack *stack)
{
	int	i;
	int	min_index;
	int	max_index;

	min_index = ft_get_min_num(stack, 'a');
	max_index = ft_get_max_num(stack, 'a');
	i = ft_get_case(stack, min_index, max_index);
	if (i == 1)
	{
		ft_reverse_a(stack, 0);
		ft_swap_a(stack, 0);
	}
	else if (i == 2)
		ft_rotate_a(stack, 0);
	else if (i == 3)
	{
		ft_rotate_a(stack, 0);
		ft_swap_a(stack, 0);
	}
	else if (i == 4)
		ft_swap_a(stack, 0);
	else if (i == 5)
		ft_reverse_a(stack, 0);
}
