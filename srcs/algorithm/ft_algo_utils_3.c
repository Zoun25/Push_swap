/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:00:17 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/04/21 03:00:19 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	ft_find_close_b(t_stack *stack, int key)
{
	t_list	*tmp;
	int		min;
	int		med;
	int		b;

	tmp = stack->b.first;
	b = 0;
	min = -1;
	med = ft_get_min_num(stack, 'b');
	while (b < (int)stack->b.len)
	{
		if ((int)(long)tmp->content < key && (int)(long)tmp->content >= med)
		{
			min = (int)(long)tmp->content;
			med = min;
		}
		tmp = tmp->next;
		b++;
	}
	if (min != -1)
		return (ft_find_first_lk(stack, 'b', min));
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
	while (a < (int)stack->a.len)
	{
		if (key < (int)(long)tmp->content && (int)(long)tmp->content <= med)
		{
			max = (int)(long)tmp->content;
			med = max;
		}
		tmp = tmp->next;
		a++;
	}
	if (max != -1)
		return (ft_find_first_lk(stack, 'a', max));
	return (max);
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
int	ft_find_first_lk(t_stack *stack, char type, int key)
{
	int		i;
	int		len;
	t_list	*tmp;

	if (type == 'a')
	{
		len = stack->a.len;
		tmp = stack->a.first;
	}
	else
	{
		len = stack->b.len;
		tmp = stack->b.first;
	}
	i = 0;
	while (i < len)
	{
		if ((int)(long)tmp->content == key)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
