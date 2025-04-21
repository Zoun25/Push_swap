/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fails.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:54:01 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/04/21 02:54:03 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
revisa B


ft_printf("NUM: %d ", ft_get_val_idx(stack, 'a', idx_a));
		if (low_idx == -1)
		{
			ft_printf("MAX: %d ", max_idx);
			ft_printf("MAX_VAL: %d\n", ft_get_val_idx(stack, 'b', max_idx));
			cost = ft_cal_cost(stack, idx_a, max_idx);
		}
		else
		{
			ft_printf("LOW: %d ", low_idx);
			ft_printf("LOW_VAL: %d\n", ft_get_val_idx(stack, 'b', low_idx));
			cost = ft_cal_cost(stack, idx_a, low_idx);
		}

revisa A


ft_printf("NUM: %d ", ft_get_val_idx(stack, 'b', idx_b));
		if (sup_idx == -1)
		{
			ft_printf("MIN: %d ", min_idx);
			ft_printf("MIN_VAL: %d\n", ft_get_val_idx(stack, 'a', min_idx));
			cost = ft_cal_cost(stack, min_idx, idx_b);
		}
		else
		{
			ft_printf("SUP: %d ", sup_idx);
			ft_printf("SUP_VAL: %d\n", ft_get_val_idx(stack, 'a', sup_idx));
			cost = ft_cal_cost(stack, sup_idx, idx_b);
		}

		ft_print_stacks(stack);
	ft_printf("NUM_VAL: %d ", ft_get_val_idx(stack, 'b', *index_b));
	ft_printf("NUM_IDX: %d ", *index_b);
	ft_printf("MIN: %d ", min_idx);
	ft_printf("MIN_VAL: %d ", ft_get_val_idx(stack, 'a', min_idx));
	idx = ft_find_close_a(stack, ft_get_val_idx(stack, 'b', *index_b));
	if (idx != -1)
	{
		ft_printf("SUP: %d ", idx);
		ft_printf("SUP_VAL: %d ", ft_get_val_idx(stack, 'a', idx));
	}
	ft_printf("COST: %d\n", lcost);



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
/* int	ft_comp_lis(t_stack *stack, int index, int *moves_a, int *moves_b)
{
	int	target;
	int	x;
	int	total_moves;

	x = ft_getval(stack, index, 'b');
	if (index <= (int)stack->b.len / 2)
		*moves_b = index;
	else
		*moves_b = -((int)stack->b.len - index);
	int	min_val;
	int	max_val;
	int	min_idx;

	min_val = ft_get_min_num(stack, 'a');
	max_val = ft_get_max_num(stack, 'a');
	min_idx = ft_get_min_index(stack, 'a');
	if (x < min_val || x > max_val)
		target = min_idx;
	else
		target = ft_find_first_sk(stack->a.first, x);
	if (target <= (int)stack->a.len / 2)
		*moves_a = target;
	else
		*moves_a = -((int)stack->a.len - target);
	if ((*moves_a >= 0 && *moves_b >= 0) || (*moves_a < 0 && *moves_b < 0))
	{
		if (ft_abs(*moves_a) > ft_abs(*moves_b))
			total_moves = ft_abs(*moves_a);
		else
			total_moves = ft_abs(*moves_b);
	}
	else
		total_moves = ft_abs(*moves_a) + ft_abs(*moves_b);
	return (total_moves);
}

int	ft_is_in_lis(int pos, int *lis, int lis_len)
{
	if (pos > lis_len)
		return (0);
	if (lis[pos] == 1)
		return (1);
	return (0);
}

void	ft_exec_moves(t_stack *stack, int moves_a, int moves_b)
{
	if (moves_a > 0 && moves_b > 0)
	{
		while (moves_a-- > 0 && moves_b-- > 0)
			ft_rotate(stack);
	}
	else if (moves_a < 0 && moves_b < 0)
	{
		while (moves_a++ < 0 && moves_b++ < 0)
			ft_reverse(stack);
	}
	else
	{
		while (moves_a-- > 0)
			ft_rotate_a(stack);
		while (moves_b-- > 0)
			ft_rotate_b(stack);
		while (moves_a++ < 0)
			ft_reverse_a(stack);
		while (moves_b++ < 0)
			ft_reverse_b(stack);
	}
}

void	ft_sort_100(t_stack *stack)
{
	int	lis_len;
	int	*lis;
	int	i;
	int	moves;
	int	idx;

	ft_print_stacks(stack);
	lis = ft_lis(stack, &lis_len);
	if (!lis)
		ft_push_error(1);
	i = 0;
	while (i < (int)stack->a.len)
	{
		if (ft_is_in_lis(i++, lis, lis_len))
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
			i++;
		}
		i = 0;
		if (idx <= (int)stack->b.len / 2)
			while (i++ < idx)
				ft_rotate_b(stack);
		else
			while (i++ < ((int)stack->b.len - idx))
				ft_reverse_b(stack);
		ft_print_stacks(stack);
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
} */
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

/* void	ft_amoves(t_stack *stack, int *srt, int i, int cut)
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
}*/
/* int	ft_cal_cost(t_stack *stack, int idx_a, int idx_b)
{
	int	cost;
	int	a;
	int	b;

	if (idx_a <= ((int)stack->a.len - idx_a))
		a = idx_a;
	else
		a = ((int)stack->a.len - idx_a);
	if (idx_b <= ((int)stack->b.len - idx_b))
		b = idx_b;
	else
		b = ((int)stack->b.len - idx_b);
	if ((idx_a == a && idx_b == b) || (idx_a != a && idx_b != b)
		|| (idx_a == a && idx_b != b && stack->a.len % 2 == 0)
		|| (idx_b == b && idx_a != a && stack->b.len % 2 == 0))
	{
		cost = a;
		if (b > cost)
			cost = b;
	}
	else
		cost = a + b;
	return (cost);
} */
/* int	ft_getval(t_stack *stack, int index, char type)
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



void	ft_print_stacks(t_stack *stack)
{
	t_list	*tmp;
	int		l;

	ft_printf("\nStack A (len = %i):\n", stack->a.len);
	tmp = stack->a.first;
	l = stack->a.len;
	while (l-- > 0)
	{
		ft_printf("%d ", (int)((long)tmp->content));
		tmp = tmp->next;
	}
	ft_printf("\n");
	ft_printf("Stack B (len = %i):\n", stack->b.len);
	tmp = stack->b.first;
	l = stack->b.len;
	while (l-- > 0)
	{
		if (tmp->content)
			ft_printf("%d ", (int)((long)tmp->content));
		else
			ft_printf("NULL ");
		tmp = tmp->next;
	}
	ft_printf("\n");
}

 */
