/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:31:41 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 17:26:30 by pillesca         ###   ########.fr       */
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
 * Similar to ft_rotate_stack shifts all the numbers in the stack array by one 
 * position, and swaps the * first and last positions. Only in the opposite
 * direction
 * 
 * @param[in] stack Stack to rotate
*/
void	ft_inv_rotation(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stack->array[0];
	stack->array[0] = stack->array[stack->size - 1];
	stack->array[stack->size - 1] = tmp;
	while (i < stack->size - 2)
	{
		tmp = stack->array[i];
		stack->array[i] = stack->array[i - 1];
		stack->array[i - 1] = tmp;
		i++;
	}
}
