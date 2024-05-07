/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:46:39 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/07 13:50:34 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Rotate both stacks and push
 * 
 * @param[in] a Reference to stack a
 * @param[in] b Reference to stack b
 * @param[in] move Struct with the number tu push and target stack
 * @return -1 to reduce moves on call function
*/
int	ft_apply_rarb(t_stack *a, t_stack *b, t_move move)
{
	if (move.destination == b_stack)
	{
		while (a->array[a->size - 1] != move.nb
			&& ft_find_new_b(b, move.nb) > 0)
			ft_rr(a, b);
		while (a->array[a->size - 1] != move.nb)
			ft_ra(a);
		while (ft_find_new_b(b, move.nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (b->array[b->size - 1] != move.nb
			&& ft_find_new_a(a, move.nb) > 0)
			ft_rr(a, b);
		while (b->array[b->size - 1] != move.nb)
			ft_rb(b);
		while (ft_find_new_a(a, move.nb) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * Reverse Rotate both stacks and push
 * 
 * @param[in] a Reference to stack a
 * @param[in] b Reference to stack b
 * @param[in] move Struct with the number tu push and target stack
 * @return -1 to reduce moves on call function
*/
int	ft_apply_rrarrb(t_stack *a, t_stack *b, t_move move)
{
	if (move.destination == b_stack)
	{
		while (a->array[a->size - 1] != move.nb
			&& ft_find_new_b(b, move.nb) > 0)
			ft_rrr(a, b);
		while (a->array[a->size - 1] != move.nb)
			ft_rra(a);
		while (ft_find_new_b(b, move.nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (b->array[b->size - 1] != move.nb
			&& ft_find_new_a(a, move.nb) > 0)
			ft_rrr(a, b);
		while (b->array[b->size - 1] != move.nb)
			ft_rrb(b);
		while (ft_find_new_a(a, move.nb) > 0)
			ft_rra(a);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * Rotates stack b and Reverse Rotates stack a and push
 * 
 * @param[in] a Reference to stack a
 * @param[in] b Reference to stack b
 * @param[in] move Struct with the number tu push and target stack
 * @return -1 to reduce moves on call function
*/
int	ft_apply_rrarb(t_stack *a, t_stack *b, t_move move)
{
	if (move.destination == b_stack)
	{
		while (a->array[a->size - 1] != move.nb)
			ft_rra(a);
		while (ft_find_new_b(b, move.nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_new_a(a, move.nb) > 0)
			ft_rra(a);
		while (b->array[b->size - 1] != move.nb)
			ft_rb(b);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * Rotates stack a and Reverse Rotates stack b and push
 * 
 * @param[in] a Reference to stack a
 * @param[in] b Reference to stack b
 * @param[in] move Struct with the number tu push and target stack
 * @return -1 to reduce moves on call function
*/
int	ft_apply_rarrb(t_stack *a, t_stack *b, t_move move)
{
	if (move.destination == b_stack)
	{
		while (a->array[a->size - 1] != move.nb)
			ft_ra(a);
		while (ft_find_new_b(b, move.nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_new_a(a, move.nb) > 0)
			ft_ra(a);
		while (b->array[b->size - 1] != move.nb)
			ft_rrb(b);
		ft_pa(a, b);
	}
	return (-1);
}
