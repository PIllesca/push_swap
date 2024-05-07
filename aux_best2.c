/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_best2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:14:48 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/07 19:05:46 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * This function calculates how many times we need to rotate both stacks.
 * Returns whichever is lowest the new position in stack b or current position 
 * in stack a.
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @returns Struck with the number to move and in how many moves
*/
static t_move	ft_ba_rarb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_move	move;

	move.destination = a_stack;
	move.rotation = rarb;
	move.nb = nb;
	move.c = ft_find_new_a(stack_a, nb);
	if (move.c < ft_find_index(stack_b, nb))
		move.c = ft_find_index(stack_b, nb);
	return (move);
}

/**
 * This function calculates how many times we need to rotate both stacks in
 * reverse. Because the rotation is in reverse we subtrack to the stack size
 * the new postion in stack b or current position in stack a and return 
 * whichever is lowest.
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @returns Struck with the number to move and in how many moves
*/
static t_move	ft_ba_rrarrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = a_stack;
	move.rotation = rrarrb;
	move.nb = nb;
	if (ft_find_new_a(stack_a, nb))
		move.c = stack_a->size - ft_find_new_a(stack_a, nb);
	if (ft_find_index(stack_b, nb)
		&& (move.c < (stack_b->size - ft_find_index(stack_b, nb))))
		move.c = stack_b->size - ft_find_index(stack_b, nb);
	return (move);
}

/**
 * This function calculates how many times we need to rotate stack a and 
 * reverse rotate stack b. Returns the sum of the reverse rotations of
 * stack b and the rotations of stack a
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @returns Struck with the number to move and in how many moves
*/
static t_move	ft_ba_rrarb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = a_stack;
	move.rotation = rrarb;
	move.nb = nb;
	if (ft_find_new_a(stack_a, nb))
		move.c = stack_a->size - ft_find_new_a(stack_a, nb);
	move.c = ft_find_index(stack_b, nb) + move.c;
	return (move);
}

/**
 * This function calculates how many times we need to rotate stack b and 
 * reverse rotate stack a. Returns the sum of the reverse rotations of stack a
 * and the rotations of stack b.
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @returns Struck with the number to move and in how many moves
*/
static t_move	ft_ba_rarrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = a_stack;
	move.rotation = rarrb;
	move.nb = nb;
	if (ft_find_index(stack_b, nb))
		move.c = stack_b->size - ft_find_index(stack_b, nb);
	move.c = ft_find_new_a(stack_a, nb) + move.c;
	return (move);
}

/**
 * Finds the least amount of moves to prepare to make push b. Checks how many
 * moves it would take to prepare both stacks for the push for each element of
 * stack a and returns the least amount of moves posible.
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @returns Struck with the number to move and in how many moves
*/
t_move	ft_best_ba_rotation(t_stack *stack_a, t_stack *stack_b)
{
	int		index;
	t_move	move;

	index = 0;
	move = ft_ba_rrarrb(stack_a, stack_b, stack_b->array[index]);
	while (index < stack_b->size)
	{
		if (move.c > ft_ba_rarb(stack_a, stack_b, stack_b->array[index]).c)
			move = ft_ba_rarb(stack_a, stack_b, stack_b->array[index]);
		if (move.c > ft_ba_rrarrb(stack_a, stack_b, stack_b->array[index]).c)
			move = ft_ba_rrarrb(stack_a, stack_b, stack_b->array[index]);
		if (move.c > ft_ba_rarrb(stack_a, stack_b, stack_b->array[index]).c)
			move = ft_ba_rarrb(stack_a, stack_b, stack_b->array[index]);
		if (move.c > ft_ba_rrarb(stack_a, stack_b, stack_b->array[index]).c)
			move = ft_ba_rrarb(stack_a, stack_b, stack_b->array[index]);
		index++;
	}
	return (move);
}
