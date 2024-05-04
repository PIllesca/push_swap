/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:14:34 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 15:42:22 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

void	ft_error_exit(void);
void	ft_free_str(char **str);
long	ft_atol(const char *str);
int		ft_chk_args(int argc, char *argv[]);
t_stack	*ft_create_stack(int size);
void	ft_destroy_stack(t_stack *stack);
void	ft_push_stack(t_stack *stack, int nb);
int		ft_pop_stack(t_stack *stack);
void	ft_swap_stack(t_stack *stack);
void	ft_rotate_stack(t_stack *stack);
void	ft_inv_rotation(t_stack *stack);
void	ft_push_swap(int argc, char *argv[], int c);

#endif /*PUSH_SWAP_H*/
