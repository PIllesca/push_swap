/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:10:18 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 23:47:51 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Swaps the two top elements of Stack a and prints sa on the terminal
 * 
 * @param[in] stack_a Reference to Stack a
*/
void	ft_sa(t_stack *stack_a)
{
	ft_swap_stack(stack_a);
	ft_putendl_fd("sa", 1);
}

/**
 * Swaps the two top elements of Stack b and prints sb on the terminal
 * 
 * @param[in] stack_b Reference to Stack b
*/
void	ft_sb(t_stack *stack_b)
{
	ft_swap_stack(stack_b);
	ft_putendl_fd("sb", 1);
}

/**
 * Swaps the two top elements of Stack a and b and prints ss on the terminal
 * 
 * @param[in] stack_a Reference to Stack a
 * @param[in] stack_b Reference to Stack b
*/
void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_stack(stack_a);
	ft_swap_stack(stack_b);
	ft_putendl_fd("ss", 1);
}

/**
 * If Stack b isn't empty it takes the top element of Stack b, puts it as the 
 * top element of Stack a and prints pa on the terminal
 * 
 * @param[in] stack_a Reference to Stack a
 * @param[in] stack_b Reference to Stack b
*/
void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 0)
	{
		ft_push_stack(stack_a, ft_pop_stack(stack_b));
		ft_putendl_fd("pa", 1);
	}
}

/**
 * If Stack a isn't empty it takes the top element of Stack a, puts it as the 
 * top element of Stack b and prints pb on the terminal
 * 
 * @param[in] stack_a Reference to Stack a
 * @param[in] stack_b Reference to Stack b
*/
void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 0)
	{
		ft_push_stack(stack_b, ft_pop_stack(stack_a));
		ft_putendl_fd("pb", 1);
	}
}
