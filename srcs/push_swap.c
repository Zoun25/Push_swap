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

void	ft_init(t_stack *stack)
{
	ft_memset(stack, 0, sizeof(t_stack));
	ft_lst_init(&stack->a, NULL);
	ft_lst_init(&stack->b, NULL);
}

void	ft_check_stack(t_stack *stack, char **argv)
{
	int		*stack_a;
	size_t	a;

	a = 0;
	/* if (stack->size == 2)
		stack = ft_split_stack_single(argv);
	else */
	ft_printf("size: %i\n", stack->size);
		stack_a = ft_split_stack(argv, stack->size);
	while (a < stack->size)
	{
		printf("number: %i\n", stack_a[a]);
		a++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc > 2)
	{
		ft_init(&stack);
		stack.size = argc;
		ft_check_stack(&stack, argv);
	}
	return (0);
}
