/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:38:54 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 00:01:19 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Similar to ft_rotate_stack shifts all the numbers in the stack array by one 
 * position, and swaps the * first and last positions. Only in the opposite
 * direction
 * 
 * @param[in] stack Stack to rotate
*/
void	ft_reverse_rotation(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stack->array[0];
	stack->array[0] = stack->array[stack->size - 1];
	stack->array[stack->size - 1] = tmp;
	while (i < stack->size - 1)
	{
		tmp = stack->array[i];
		stack->array[i] = stack->array[i - 1];
		stack->array[i - 1] = tmp;
		i++;
	}
}

/**
 * Reverse rotates Stack a and prints rra on the terminal
 * 
 * @param[in] stack_a Reference to Stack a
*/
void	ft_rra(t_stack *stack_a)
{
	ft_reverse_rotation(stack_a);
	ft_putendl_fd("rra", 1);
}

/**
 * Reverse rotates Stack b and prints rrb on the terminal
 * 
 * @param[in] stack_b Reference to Stack b
*/
void	ft_rrb(t_stack *stack_b)
{
	ft_reverse_rotation(stack_b);
	ft_putendl_fd("rrb", 1);
}

/**
 * Reverse rotates Stack a and Stack b and prints rrr on the terminal
 * 
 * @param[in] stack_a Reference to Stack a
 * @param[in] stack_b Reference to Stack b
*/
void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotation(stack_a);
	ft_reverse_rotation(stack_b);
	ft_putendl_fd("rrr", 1);
}
