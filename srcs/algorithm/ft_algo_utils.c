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
	min_index = 1;
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
	max_index = 1;
	while ((int)(long)tmp->content != ft_get_max_num(stack, type))
	{
		tmp = tmp->next;
		max_index++;
	}
	return (max_index);
}

int	ft_get_min_num(t_stack *stack, char type)
{
	int		min_index;
	int		len;
	t_list	*tmp;

	if (type == 'a')
	{
		tmp = stack->a.first;
		len = (int)stack->a.len;
	}
	else
	{
		tmp = stack->b.first;
		len = (int)stack->b.len;
	}
	min_index = (int)(long)tmp->content;
	while (len > 0)
	{
		if ((int)(long)tmp->content < min_index)
			min_index = (int)(long)tmp->content;
		tmp = tmp->next;
		len--;
	}
	return (min_index);
}

int	ft_get_max_num(t_stack *stack, char type)
{
	int		max_index;
	int		len;
	t_list	*tmp;

	if (type == 'a')
	{
		tmp = stack->a.first;
		len = (int)stack->a.len;
	}
	else
	{
		tmp = stack->b.first;
		len = (int)stack->b.len;
	}
	max_index = (int)(long)tmp->content;
	while (len > 0)
	{
		if ((int)(long)tmp->content > max_index)
			max_index = (int)(long)tmp->content;
		tmp = tmp->next;
		len--;
	}
	return (max_index);
}

int	ft_find_first_lk(t_list *lst, int key)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp ->next)
	{
		if ((int)(long)tmp->content == key)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

t_list	*ft_get_last_node(t_stack *stack, char type)
{
	t_list	*tmp;

	if (type == 'a')
		tmp = stack->a.first;
	else
		tmp = stack->b.first;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	*ft_bubble(int *sorted_array, int size)
{
	int	i;
	int	b;
	int	tmp;

	b = 1;
	while (b)
	{
		b = 0;
		i = 0;
		while (i < size)
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

int	*ft_getsorted(t_stack *stack)
{
	int		*sorted_array;
	int		i;

	i = 0;
	sorted_array = (int *)malloc(sizeof(int *) * stack->size);
	if (sorted_array == NULL)
		return (NULL);
	while (i < (int)stack->size)
	{
		sorted_array[i] = stack->knot[i];
		i++;
	}
	sorted_array = ft_bubble(sorted_array, ((int)stack->size -1));
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

int	ft_get_case(t_stack *stack, int min_index, int max_index)
{
	t_list	*tmp;
	int		actual_index;

	tmp = stack->a.first;
	actual_index = (int)(long)tmp->content;
	if (actual_index != min_index && actual_index != max_index)
	{
		if ((int)(long)tmp->next->content == min_index)
			return (1);
	}
	else if (actual_index == max_index)
	{
		if ((int)(long)tmp->next->content == min_index)
			return (3);
		else
			return (2);
	}
	else if (actual_index == min_index)
		return (4);
	return (5);
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
		ft_swap_a(stack);
	else if (i == 2)
	{
		ft_swap_a(stack);
		ft_reverse_a(stack);
	}
	else if (i == 3)
		ft_rotate_a(stack);
	else if (i == 4)
	{
		ft_swap_a(stack);
		ft_rotate_a(stack);
	}
	else if (i == 5)
		ft_reverse_a(stack);
}
