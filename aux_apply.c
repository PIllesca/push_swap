/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:00 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 14:56:53 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	ft_apply_rarb(t_stack *a, t_stack *b, t_move move)
{
	if (move.destination == b_stack)
	{
		while (a->nb != move.nb && ft_find_new_b(b, move.nb) > 0)
			ft_rr(a, b);
		while (a->nb != move.nb)
			ft_ra(a);
		while (ft_find_new_b(b, move.nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (b->nb != move.nb && ft_find_new_a(a, move.nb) > 0)
			ft_rr(a, b);
		while (b->nb != move.nb)
			ft_rb(b);
		while (ft_find_new_a(a, move.nb) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
int	ft_apply_rrarrb(t_stack *a, t_stack *b, t_move move)
{
	if (move.destination == b_stack)
	{
		while (a->nb != move.nb && ft_find_new_b(b, move.nb) > 0)
			ft_rrr(a, b);
		while (a->nb != move.nb)
			ft_rra(a);
		while (ft_find_new_b(b, move.nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (b->nb != move.nb && ft_find_new_a(a, move.nb) > 0)
			ft_rrr(a, b);
		while (b->nb != move.nb)
			ft_rrb(b);
		while (ft_find_new_a(a, move.nb) > 0)
			ft_rra(a);
		ft_pa(a, b);
	}
	return (-1);
}

// This function rotate the stack_a in reverse direction,
// the stack_b in oppsite direction of stack_a as required amount.
int	ft_apply_rrarb(t_stack *a, t_stack *b, t_move move)
{
	if (move.destination == b_stack)
	{
		while (a->nb != move.nb)
			ft_rra(a);
		while (ft_find_new_b(b, move.nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_new_a(a, move.nb) > 0)
			ft_rra(a);
		while (b->nb != move.nb)
			ft_rb(b);
		ft_pa(a, b);
	}
	return (-1);
}

// This function rotate the stack_b in reverse direction,
// the stack_a in oppsite direction of stack_a as required amount.
int	ft_apply_rarrb(t_stack *a, t_stack *b, t_move move)
{
	if (move.destination == b_stack)
	{
		while (a->nb != move.nb)
			ft_ra(a);
		while (ft_find_new_b(b, move.nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_new_a(a, move.nb) > 0)
			ft_ra(a);
		while (b->nb != move.nb)
			ft_rrb(b);
		ft_pa(a, b);
	}
	return (-1);
}