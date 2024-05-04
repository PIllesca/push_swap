/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:31:41 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 23:54:36 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Shifts all the numbers in the stack array by one position, and swaps the 
 * first and last positions.
 * 
 * @param[in] stack Stack to rotate
*/
void	ft_rotate_stack(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->size - 1;
	tmp = stack->array[0];
	stack->array[0] = stack->array[i];
	stack->array[i] = tmp;
	while (i > 1)
	{
		tmp = stack->array[i];
		stack->array[i] = stack->array[i - 1];
		stack->array[i - 1] = tmp;
		i--;
	}
}

/**
 * Rotates Stack a and prints ra on the terminal
 * 
 * @param[in] stack_a Reference to Stack a
*/
void	ft_ra(t_stack *stack_a)
{
	ft_rotate_stack(stack_a);
	ft_putendl_fd("ra", 1);
}

/**
 * Rotates Stack b and prints rb on the terminal
 * 
 * @param[in] stack_b Reference to Stack b
*/
void	ft_rb(t_stack *stack_b)
{
	ft_rotate_stack(stack_b);
	ft_putendl_fd("rb", 1);
}

/**
 * Rotates Stack a and Stack b and prints rr on the terminal
 * 
 * @param[in] stack_a Reference to Stack a
 * @param[in] stack_b Reference to Stack b
*/
void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate_stack(stack_a);
	ft_rotate_stack(stack_b);
	ft_putendl_fd("rr", 1);
}
