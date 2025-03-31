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

#endif
