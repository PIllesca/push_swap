/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_best.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:26:37 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 17:19:57 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * This function calculates how many times we need to rotate both stacks
*/
int	ft_case_rarb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	moves;

	moves = ft_find_new_b(stack_b, nb);
	if (moves < ft_find_index(stack_a, nb))
		moves = ft_find_index(stack_a, nb);
	return (moves);
}

/**
 * This function calculates how many times we need to rotate both stacks in
 * reverse
*/
int	ft_case_rrarrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	moves;

	moves = 0;
	if (ft_find_new_b(stack_b, nb))
		moves = stack_b->size - ft_find_new_b(stack_b, nb);
	if ((moves < (stack_a->size - ft_find_index(stack_a, nb)))
		&& ft_find_index(stack_a, nb))
		moves = stack_a->size - ft_find_index(stack_a, nb);
	return (moves);
}

/**
 * This function calculates how many times we need to rotate stack b and 
 * reverse rotate stack a
*/
int	ft_case_rrarb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	moves;

	moves = 0;
	if (ft_find_index(stack_a, nb))
		moves = stack_a->size - ft_find_index(stack_a, nb);
	moves = ft_find_new_b(stack_b, nb) + moves;
	return (moves);
}

/**
 * This function calculates how many times we need to rotate stack a and 
 * reverse rotate stack b
*/
int	ft_case_rarrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	moves;

	moves = 0;
	if (ft_find_new_b(stack_b, nb))
		moves = stack_b->size - ft_find_new_b(stack_b, nb);
	moves = ft_find_index(stack_a, nb) + moves;
	return (moves);
}

/**
 * Finds the best rotation to make push b
*/
int	ft_best_ab_rotation(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	moves;

	index = 0;
	moves = ft_case_rrarrb(stack_a, stack_b, stack_a->array[index]);
	while (index < stack_a->size)
	{
		if (moves > ft_case_rarb(stack_a, stack_b, stack_a->array[index]))
			moves = ft_case_rarb(stack_a, stack_b, stack_a->array[index]);
		if (moves > ft_case_rrarrb(stack_a, stack_b, stack_a->array[index]))
			moves = ft_case_rrarrb(stack_a, stack_b, stack_a->array[index]);
		if (moves > ft_case_rarrb(stack_a, stack_b, stack_a->array[index]))
			moves = ft_case_rarrb(stack_a, stack_b, stack_a->array[index]);
		if (moves > ft_case_rrarb(stack_a, stack_b, stack_a->array[index]))
			moves = ft_case_rrarb(stack_a, stack_b, stack_a->array[index]);
		index++;
	}
	return (moves);
}
