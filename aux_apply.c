/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:00 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 18:23:41 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * This function rotates both stacks to prepare the push and executes the push
 * 
 * @param a The stack a.
 * @param b The stack b.
 * @param move The move to be executed.
 * @return -1 if the operation was successful, 0 otherwise.
*/
int	ft_apply_rarb(t_stack **a, t_stack **b, t_move move)
{
	if (move.destination == b_stack)
	{
		while ((*a)->nb != move.nb && ft_find_new_b(*b, move.nb) > 0)
			ft_rr(a, b);
		while ((*a)->nb != move.nb)
			ft_ra(a);
		while (ft_find_new_b(*b, move.nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->nb != move.nb && ft_find_new_a(*a, move.nb) > 0)
			ft_rr(a, b);
		while ((*b)->nb != move.nb)
			ft_rb(b);
		while (ft_find_new_a(*a, move.nb) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * This function reverse rotates both stacks to prepare the push and executes
 * the push
 * 
 * @param a The stack a.
 * @param b The stack b.
 * @param move The move to be executed.
 * @return -1 if the operation was successful, 0 otherwise.
*/
int	ft_apply_rrarrb(t_stack **a, t_stack **b, t_move move)
{
	if (move.destination == b_stack)
	{
		while ((*a)->nb != move.nb && ft_find_new_b(*b, move.nb) > 0)
			ft_rrr(a, b);
		while ((*a)->nb != move.nb)
			ft_rra(a);
		while (ft_find_new_b(*b, move.nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->nb != move.nb && ft_find_new_a(*a, move.nb) > 0)
			ft_rrr(a, b);
		while ((*b)->nb != move.nb)
			ft_rrb(b);
		while (ft_find_new_a(*a, move.nb) > 0)
			ft_rra(a);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * This function rotates the stack b and reverse rotates the stack a as required
 * to prepare the push and executes the push
 * 
 * @param a The stack a.
 * @param b The stack b.
 * @param move The move to be executed.
 * @return -1 if the operation was successful, 0 otherwise.
*/
int	ft_apply_rrarb(t_stack **a, t_stack **b, t_move move)
{
	if (move.destination == b_stack)
	{
		while ((*a)->nb != move.nb)
			ft_rra(a);
		while (ft_find_new_b(*b, move.nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_new_a(*a, move.nb) > 0)
			ft_rra(a);
		while ((*b)->nb != move.nb)
			ft_rb(b);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * This functions rotates the stack a and reverse rotates the stack b as required
 * to prepare the push and executes the push
 * 
 * @param a The stack a.
 * @param b The stack b.
 * @param move The move to be executed.
 * @return -1 if the operation was successful, 0 otherwise.
*/
int	ft_apply_rarrb(t_stack **a, t_stack **b, t_move move)
{
	if (move.destination == b_stack)
	{
		while ((*a)->nb != move.nb)
			ft_ra(a);
		while (ft_find_new_b(*b, move.nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_new_a(*a, move.nb) > 0)
			ft_ra(a);
		while ((*b)->nb != move.nb)
			ft_rrb(b);
		ft_pa(a, b);
	}
	return (-1);
}
