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

void	ft_init(t_stack *stack, int size)
{
	ft_memset(stack, 0, sizeof(t_stack));
	stack->size = size - 1;
	ft_lst_init(&stack->a, NULL);
	ft_lst_init(&stack->b, NULL);
}

void	ft_check_stack(t_stack *stack, char **argv)
{
	if (stack->size == 1)
		stack->knot = ft_stack_single(argv[1], stack);
	else
		stack->knot = ft_stack_multi(argv, stack->size);
	if (stack->knot == NULL)
	{
		free(stack);
		ft_push_error(87);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc >= 2)
	{
		ft_init(&stack, argc);
		ft_check_stack(&stack, argv);
		stack.a = ft_create_stack(&stack);
		stack.b = ft_create_stack(&stack);
	}
	return (0);
}
