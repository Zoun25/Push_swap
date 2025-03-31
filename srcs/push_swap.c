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
	stack->a.del = NULL;
	i = 0;
	while (i < stack->size)
	{
		new_node = ft_lstnew((void *)((long)stack->knot[i]));
		if (!new_node)
			return ;
		ft_lstadd_back(&stack->a.first, new_node);
		stack->a.len++;
		i++;
	}
}

void	ft_create_stack_b(t_stack *stack)
{
	size_t	j;
	t_list	*new_node;

	stack->b.first = NULL;
	stack->b.len = 0;
	stack->b.del = NULL;

	j = 0;
	while (j < stack->a.len)
	{
		new_node = ft_lstnew(NULL);
		if (!new_node)
			return ;
		ft_lstadd_back(&stack->b.first, new_node);
		stack->b.len++;
		j++;
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
		{
			free(stack.knot);
			stack.knot = NULL;
			return (0);
		}
		ft_create_stack_a(&stack);
		ft_print_stacks(&stack);
		ft_rotate_a(&stack);
		ft_print_stacks(&stack);
		ft_lstfree(&stack);
	}
	return (0);
}

void	ft_print_stacks(t_stack *stack)
{
	t_list	*tmp;

	ft_printf("\nStack A (len = %i):\n", stack->a.len);
	tmp = stack->a.first;
	while (tmp)
	{
		ft_printf("%d ", (int)((long)tmp->content));
		tmp = tmp->next;
	}
	ft_printf("\n");

	ft_printf("Stack B (len = %i):\n", stack->b.len);
	tmp = stack->b.first;
	while (tmp)
	{
		if (tmp->content)
			ft_printf("%d ", (int)((long)tmp->content));
		else
			ft_printf("NULL ");
		tmp = tmp->next;
	}
	ft_printf("\n");
}
