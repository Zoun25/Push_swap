#include "../include/push_swap.h"

void	ft_push_error(int nberr)
{
	write(2, "Error\n", 7);
	exit(nberr);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	ft_check_arg(char *stack, int b)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	if (stack[0] == '-' || stack[0] == '+')
		i++;
	if (stack[i] == '0' && stack[i + 1] == '\0')
		return (1);
	while (ft_isdigit(stack[i]))
		i++;
	if (stack[i] != '\0')
		return (0);
	if (ft_atoi(stack) == 0)
		return (0);
	else
		return (b);
}

int	*ft_stack_multi(char **argv, int size)
{
	int	i;
	int	b;
	int	p;
	int	*stack;

	i = 0;
	p = 0;
	b = 1;
	if (ft_strncmp(argv[0], "./push_swap", 12) == 0)
		i++;
	stack = (int *)malloc(sizeof(int *) * size);
	if (stack == NULL)
		return (NULL);
	while (argv[i] && p <= size)
	{
		if (b == 1)
			b = ft_check_arg(argv[i], b);
		else
		{
			free(stack);
			return (NULL);
		}
		stack[p++] = ft_atoi(argv[i++]);
	}
	return (stack);
}


int	*ft_stack_single(char *argv, t_stack *stack)
{
	int		*stack_a;
	char	**split;

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
