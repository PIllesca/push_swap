/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:14:34 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/07 18:22:46 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/**
 * Contains the stack and stack size
 * 
 * @param array Int array with the content of the stack
 * @param size The size of the stack
*/
typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

typedef enum e_dest
{
	a_stack,
	b_stack
}	t_dest;

typedef enum e_rot
{
	rarb,
	rrarrb,
	rrarb,
	rarrb
}	t_rot;

/**
 * Contains the information needed to push a number to another stack
 * 
 * @param destination Enum that points which stack to push to
 * @param rotation Enum that selects with rotation to use before the push
 * @param c	How many rotations it will take to prepare the stack for the push
 * @param nb The number we will push to the other stack
*/
typedef struct s_move
{
	t_dest	destination;
	t_rot	rotation;
	int		c;
	int		nb;
}	t_move;

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
int		ft_find_index(t_stack *stack, int nb);
void	ft_sort_three(t_stack *stack);
t_move	ft_best_ab_rotation(t_stack *stack_a, t_stack *stack_b);
t_move	ft_best_ba_rotation(t_stack *stack_a, t_stack *stack_b);
int		ft_find_new_b(t_stack *stack_b, int nbr_push);
int		ft_find_new_a(t_stack *stack_a, int nb);
int		ft_apply_rarb(t_stack *a, t_stack *b, t_move move);
int		ft_apply_rrarrb(t_stack *a, t_stack *b, t_move move);
int		ft_apply_rrarb(t_stack *a, t_stack *b, t_move move);
int		ft_apply_rarrb(t_stack *a, t_stack *b, t_move move);
void	ft_leaks(void);
void	ft_print_stacks(t_stack	*stack_a, t_stack *stack_b);

#endif /*PUSH_SWAP_H*/
