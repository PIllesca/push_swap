/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:14:34 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 01:11:41 by pillesca         ###   ########.fr       */
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
void	ft_reverse_rotation(t_stack *stack);
int		ft_chk_sorted(t_stack *stack);
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_push_swap(int argc, char *argv[], int c);
int		ft_find_min(t_stack *stack);
int		ft_find_max(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_leaks(void);
void	ft_print_stacks(t_stack	*stack_a, t_stack *stack_b);

#endif /*PUSH_SWAP_H*/
