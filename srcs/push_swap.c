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

	if (argc >= 2)
	{
		stack.size = argc - 1;
		ft_check_stack(&stack, argv);
		if (stack.size == 1)
			return (free(stack.knot), 0);
		ft_create_stack_a(&stack);
		if (ft_stack_sorted(&stack, 'a'))
			return (ft_lstfree(&stack), 0);
		if (stack.size < 5)
			ft_simple_sort(&stack);
		if (stack.size > 4)
			ft_sort(&stack);
		ft_lstfree(&stack);
	}
	return (0);
}
