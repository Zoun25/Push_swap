/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <ysadki-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 01:36:57 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/03/28 01:36:59 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		free(argv[i++]);
	free(argv);
}

int	ft_norepeat(int *stack, int nb, int p)
{
	int	i;

	i = 0;
	while (i < p)
	{
		if (stack[i++] == nb)
			return (0);
	}
	return (1);
}

int	ft_check_arg(char *nb, int b, int *stack, int p)
{
	int	i;

	i = 0;
	if (nb == NULL)
		return (0);
	if (nb[0] == '-' || nb[0] == '+')
		i++;
	if (nb[i] == '0' && nb[i + 1] == '\0')
		return (1);
	while (ft_isdigit(nb[i]))
		i++;
	if (nb[i] != '\0')
		return (0);
	if (ft_atoi(nb) == 0 || ft_norepeat(stack, ft_atoi(nb), p) == 0)
		return (0);
	else
		return (b);
}

int	*ft_stack_multi(char **argv, int size)
{
	int	b;
	int	p;
	int	*stack;

	p = 0;
	b = 1;
	if (*argv == NULL)
		return (NULL);
	if (argv[0] != NULL && ft_strncmp(argv[0], "./push_swap", 12) == 0)
		argv++;
	stack = (int *)malloc(sizeof(int *) * size);
	if (stack == NULL)
		return (NULL);
	while (p < size)
	{
		if (b == 1)
			b = ft_check_arg(*argv, b, stack, p);
		if (b == 0 || *argv == NULL)
			return (free(stack), NULL);
		stack[p++] = ft_atoi(*argv++);
	}
	return (stack);
}

int	*ft_stack_single(char *argv, t_stack *stack)
{
	int		*stack_a;
	char	**split;

	if (argv == NULL)
		return (NULL);
	split = ft_split(argv, ' ');
	stack->size = ft_countwords(argv, ' ');
	if (split == NULL)
		return (NULL);
	stack_a = ft_stack_multi(split, stack->size);
	ft_free_argv(split);
	if (stack_a == NULL)
	{
		free(stack_a);
		return (NULL);
	}
	return (stack_a);
}
