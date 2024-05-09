/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_best2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:35:13 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 18:30:54 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * This funcion calculates how many rotations are needed to prepare the push.
 * Returns whichever is lowest the new position in stack a or current position
 * in stack b.
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @param[in] nb The number to be pushed
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
 * This function calculates how many times we need to reverse rotate both
 * stacks. Because the rotation is in reverse we subtrack to the stack size
 * the new postion in stack a or current position in stack b and return
 * whichever is lowest.
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @param[in] nb The number to be pushed
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
		move.c = ft_stack_size(stack_a) - ft_find_new_a(stack_a, nb);
	if (ft_find_index(stack_b, nb)
		&& (move.c < (ft_stack_size(stack_b) - ft_find_index(stack_b, nb))))
		move.c = ft_stack_size(stack_b) - ft_find_index(stack_b, nb);
	return (move);
}

/**
 * This function calculates how many times we need to rotate stack a and
 * reverse rotate stack b. Returns the sum of the reverse rotations of stack b
 * and the rotations of stack a.
 *  
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @param[in] nb The number to be pushed
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
		move.c = ft_stack_size(stack_b) - ft_find_index(stack_b, nb);
	move.c = ft_find_new_a(stack_a, nb) + move.c;
	return (move);
}

/**
 * This function calculates how many times we need to rotate stack b and
 * reverse rotate stack a. Returns the sum of the reverse rotations of
 * stack a and the rotations of stack b.
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @param[in] nb The number to be pushed
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
		move.c = ft_stack_size(stack_a) - ft_find_new_a(stack_a, nb);
	move.c = ft_find_index(stack_b, nb) + move.c;
	return (move);
}

/**
 * Finds the rotation with the least amount of moves to push a number from
 * stack b to stack a. Returns a struct with the number to move, in how many
 * moves and the rotation to be executed.
 * 
 * @param[in] stack_a Reference to stack_a
 * @param[in] stack_b Reference to stack_b
 * @returns Struck with the move to be executed
*/
t_move	ft_best_ba_rotation(t_stack *stack_a, t_stack *stack_b)
{
	t_move	move;
	t_stack	*tmp;

	tmp = stack_b;
	move = ft_ba_rarb(stack_a, stack_b, tmp->nb);
	while (tmp)
	{
		if (move.c > ft_ba_rarb(stack_a, stack_b, tmp->nb).c)
			move = ft_ba_rarb(stack_a, stack_b, tmp->nb);
		if (move.c > ft_ba_rrarrb(stack_a, stack_b, tmp->nb).c)
			move = ft_ba_rrarrb(stack_a, stack_b, tmp->nb);
		if (move.c > ft_ba_rarrb(stack_a, stack_b, tmp->nb).c)
			move = ft_ba_rarrb(stack_a, stack_b, tmp->nb);
		if (move.c > ft_ba_rrarb(stack_a, stack_b, tmp->nb).c)
			move = ft_ba_rrarb(stack_a, stack_b, tmp->nb);
		tmp = tmp->next;
	}
	return (move);
}
