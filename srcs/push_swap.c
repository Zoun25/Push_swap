/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:36:57 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/03/25 01:36:59 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_check_stack(t_stack *stack, char **argv)
{
	if (stack->size == 1)
		stack->knot = ft_stack_single(argv[1], stack);
	else
		stack->knot = ft_stack_multi(argv, stack->size);
	if (stack->knot == NULL)
		ft_push_error(87);
}

void	ft_create_stack_a(t_stack *stack)
{
	size_t	i;
	t_list	*new_node;

	stack->a.first = NULL;
	stack->a.len = 0;
	stack->b.first = NULL;
	stack->b.len = 0;
	i = 0;
	while (i < stack->size)
	{
		new_node = ft_lstnew((void *)(long)stack->knot[i]);
		if (!new_node)
			return ;
		ft_lstadd_back(&stack->a.first, new_node);
		stack->a.len++;
		i++;
	}
}

void	ft_lstfree(t_stack *stack)
{
	if (!stack)
		return ;
	ft_lstfree_cont(&stack->a);
	ft_lstfree_cont(&stack->b);
	if (stack->knot)
	{
		free(stack->knot);
		stack->knot = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*sorted_array;

	if (argc >= 2)
	{
		stack.size = argc - 1;
		ft_check_stack(&stack, argv);
		if (stack.size == 1)
			return (free(stack.knot), 0);
		ft_create_stack_a(&stack);
		sorted_array = ft_getsorted(&stack);
		if (ft_is_sorted(&stack, sorted_array))
			return (free(sorted_array), ft_lstfree(&stack), 0);
		if (stack.size < 10)
			ft_simple_sort(&stack, sorted_array);
		if (stack.size >= 10 && stack.size <= 100)
			ft_sort_100(&stack);
		/* if (stack.size > 100)
			ft_sort_500(&stack); */
		free(sorted_array);
		ft_lstfree(&stack);
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
