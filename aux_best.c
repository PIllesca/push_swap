/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_best.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:44:06 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 14:11:59 by pillesca         ###   ########.fr       */
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
static t_move	ft_ab_rarb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_move	move;

	move.destination = b_stack;
	move.rotation = rarb;
	move.nb = nb;
	move.c = ft_find_new_b(stack_b, nb);
	if (move.c < ft_find_index(stack_a, nb))
		move.c = ft_find_index(stack_a, nb);
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
static t_move	ft_ab_rrarrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = b_stack;
	move.rotation = rrarrb;
	move.nb = nb;
	if (ft_find_new_b(stack_b, nb))
		move.c = ft_stack_size(stack_b) - ft_find_new_b(stack_b, nb);
	if (ft_find_index(stack_a, nb)
		&& (move.c < (ft_stack_size(stack_a) - ft_find_index(stack_a, nb))))
		move.c = ft_stack_size(stack_a) - ft_find_index(stack_a, nb);
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
static t_move	ft_ab_rrarb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = b_stack;
	move.rotation = rrarb;
	move.nb = nb;
	if (ft_find_index(stack_a, nb))
		move.c = ft_stack_size(stack_a) - ft_find_index(stack_a, nb);
	move.c = ft_find_new_b(stack_b, nb) + move.c;
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
static t_move	ft_ab_rarrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = b_stack;
	move.rotation = rarrb;
	move.nb = nb;
	if (ft_find_new_b(stack_b, nb))
		move.c = ft_stack_size(stack_a) - ft_find_new_b(stack_b, nb);
	move.c = ft_find_index(stack_a, nb) + move.c;
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
t_move	ft_best_ab_rotation(t_stack *stack_a, t_stack *stack_b)
{
	t_move	move;
	t_stack	*tmp;

	tmp = stack_a;
	move = ft_ab_rrarrb(stack_a, stack_b, stack_a->nb);
	while (tmp)
	{
		if (move.c > ft_ab_rarb(stack_a, stack_b, stack_a->nb).c)
			move = ft_ab_rarb(stack_a, stack_b, stack_a->nb);
		if (move.c > ft_ab_rrarrb(stack_a, stack_b, stack_a->nb).c)
			move = ft_ab_rrarrb(stack_a, stack_b, stack_a->nb);
		if (move.c > ft_ab_rarrb(stack_a, stack_b, stack_a->nb).c)
			move = ft_ab_rarrb(stack_a, stack_b, stack_a->nb);
		if (move.c > ft_ab_rrarb(stack_a, stack_b, stack_a->nb).c)
			move = ft_ab_rrarb(stack_a, stack_b, stack_a->nb);
		tmp = tmp->next;
	}
	return (move);
}
