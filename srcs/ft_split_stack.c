#include "../include/push_swap.h"

void	ft_push_error(int nberr)
{
	write(2, "Error\n", 7);
	exit(nberr);
}

int	ft_check_arg(char *stack, int b)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	if (stack[i] == '-' || stack[i] == '+')
		i++;
	if (stack[i] == '0' && stack[i + 1] != '\0')
		return (1);
	if (ft_atoi(stack) == 0)
		return (0);
	else
		return (b);
}

int	*ft_split_stack(char **argv, int size)
{
	int	i;
	int	b;
	int	*stack;

	i = 0;
	b = 1;
	stack = (int *)malloc(sizeof(int) * size);
	while (argv[i++] && i < size)
	{
		if (b == 1)
			b = ft_check_arg(argv[i], b);
		if (b == 1)
			stack[i] = ft_atoi(argv[i]);
		else
		{
			free(stack);
			ft_push_error(87);
		}
	}
	return (stack);
}
