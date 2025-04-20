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

int	ft_get_min_num(t_stack *stack, char type)
{
	int		min_num;
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
	min_num = (int)(long)tmp->content;
	while (len > 0)
	{
		if ((int)(long)tmp->content < min_num)
			min_num = (int)(long)tmp->content;
		tmp = tmp->next;
		len--;
	}
	return (min_num);
}

int	ft_get_max_num(t_stack *stack, char type)
{
	int		max_num;
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
	max_num = (int)(long)tmp->content;
	while (len > 0)
	{
		if ((int)(long)tmp->content > max_num)
			max_num = (int)(long)tmp->content;
		tmp = tmp->next;
		len--;
	}
	return (max_num);
}

/*returns idx of the number if exist*/
int	ft_find_first_lk(t_list *lst, int key)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp->content)
	{
		if ((int)(long)tmp->content == key)
			return (i);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	return (-1);
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
	while (tmp->content)
	{
		if (i == val)
			return ((int)(long)tmp->content);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	if (i == val)
		return ((int)(long)tmp->content);
	return (ft_push_error(87), 0);
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

int	ft_getval(t_stack *stack, int index, char type)
{
	int		i;
	int		len;
	t_list	*tmp;

	if (index < 0 || index > (int)stack->size)
		return (-1);
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
	i = 0;
	while (i < index && i++ < len)
		tmp = tmp->next;
	return ((int)(long)tmp->content);
}

int	ft_find_first_sk(t_list *lst, int key)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp->content)
	{
		if ((int)(long)tmp->content < key)
			return (i);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	return (-1);
}

int	ft_find_close_b(t_stack *stack, int key)
{
	t_list	*tmp;
	int		min;
	int		med;
	int		a;

	tmp = stack->b.first;
	a = 0;
	min = -1;
	med = ft_get_min_num(stack, 'b');
	while (tmp->content)
	{
		if ((int)(long)tmp->content < key && (int)(long)tmp->content >= med)
		{
			a = 1;
			min = (int)(long)tmp->content;
			med = min;
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	if (a == 1)
		return (ft_find_first_lk(stack->b.first, min));
	return (min);
}

int	ft_find_close_a(t_stack *stack, int key)
{
	t_list	*tmp;
	int		max;
	int		med;
	int		a;

	tmp = stack->a.first;
	a = 0;
	max = -1;
	med = ft_get_max_num(stack, 'a');
	while (tmp->content)
	{
		if ((int)(long)tmp->content > key && (int)(long)tmp->content <= med)
		{
			a = 1;
			max = (int)(long)tmp->content;
			med = max;
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	if (a == 1)
		return (ft_find_first_lk(stack->a.first, max));
	return (max);
}
