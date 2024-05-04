/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:17:02 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 17:32:46 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Creates an empty stack of specified size
 * 
 * @param[in] size Size of the stack
 * @returns The new empty stack
*/
t_stack	*ft_create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_error_exit();
	stack->array = (int *)malloc(size * sizeof(int));
	if (stack->array == NULL)
		ft_error_exit();
	stack->size = 0;
	return (stack);
}

/**
 * Frees the asigned memory of the passed stack
 * 
 * @param stack Stack to free
*/
void	ft_destroy_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

/**
 * Adds a number to the top of the stack
 * 
 * @param[in] stack Stack to add the number to
 * @param[in] nb Number to add
*/
void	ft_push_stack(t_stack *stack, int nb)
{
	stack->array[stack->size] = nb;
	stack->size++;
}

/**
 * Deletes the top number of the stack and returns it
 * 
 * @param[in] stack Stack to remove the number from
 * @returns The removed number
*/
int	ft_pop_stack(t_stack *stack)
{
	if (stack->size > 0)
	{
		stack->size--;
		return (stack->array[stack->size]);
	}
	return (0);
}

/**
 * Swaps the two top numbers in the stack
 * 
 * @param stack The stack to work with
*/
void	ft_swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[stack->size - 1];
		stack->array[stack->size - 1] = stack->array[stack->size - 2];
		stack->array[stack->size - 2] = tmp;
	}
}
