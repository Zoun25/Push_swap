/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysadki-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:46:31 by ysadki-z          #+#    #+#             */
/*   Updated: 2025/01/16 14:46:32 by ysadki-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"

typedef struct pushswap_data
{
	t_cont	a;
	t_cont	b;
	size_t	size;
	int		*knot;
}	t_stack;

int		*ft_stack_multi(char **argv, int size);
int		*ft_stack_single(char *argv, t_stack *stack);
void	ft_push_error(int nberr);
void	ft_free_argv(char **argv);
void	ft_print_stacks(t_stack *stack);
void	ft_push_a(t_stack *stack);
void	ft_push_b(t_stack *stack);
void	ft_swap_a(t_stack *stack);
void	ft_swap_b(t_stack *stack);
void	ft_swap_ss(t_stack *stack);
void	ft_rotate_a(t_stack *stack);
void	ft_rotate_b(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_a(t_stack *stack);
void	ft_reverse_b(t_stack *stack);
void	ft_reverse(t_stack *stack);
void	ft_lstfree(t_stack *stack);
/* void	ft_sort_500(t_stack *stack); */
int		ft_is_sorted(t_stack *stack, int *srt);
int		*ft_getsorted(t_stack *stack);
int		ft_get_min_num(t_stack *stack, char type);
int		ft_get_max_num(t_stack *stack, char type);
int		ft_get_min_index(t_stack *stack, char type);
int		ft_get_max_index(t_stack *stack, char type);
int		ft_find_first_lk(t_list *lst, int key);
t_list	*ft_get_last_node(t_stack *stack, char type);
void	ft_five_cases(t_stack *stack);
void	ft_simple_sort(t_stack *stack, int *srt);
void	ft_sort_100(t_stack *stack, int *srt);
void	ft_print_stacks(t_stack *stack);

#endif
