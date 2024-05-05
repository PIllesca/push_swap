/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:46:39 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 13:14:49 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Rotate both stacks
 * 
 * @param[in] a Reference to stack a
 * @param[in] b Reference to stack b
 * @param[in] nb The number to push
 * @param[in] s Char for selecting target stack
 * @return -1 to reduce moves on call function
*/
int	ft_apply_rarb(t_stack *a, t_stack *b, int nb, char s)
{
	if (s == 'a')
	{
		while (a->array[a->size - 1] != nb && ft_find_new_b(b, nb) > 0)
			ft_rr(a, b);
		while (a->array[a->size - 1] != nb)
			ft_ra(a);
		while (ft_find_new_b(b, nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (b->array[b->size - 1] != nb && ft_find_new_a(a, nb) > 0)
			ft_rr(a, b);
		while (b->array[b->size - 1] != nb)
			ft_rb(b);
		while (ft_find_new_a(a, nb) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * Reverse Rotate both stacks
 * 
 * @param[in] a Reference to stack a
 * @param[in] b Reference to stack b
 * @param[in] nb The number to push
 * @param[in] s Char for selecting target stack
 * @return -1 to reduce moves on call function
*/
int	ft_apply_rrarrb(t_stack *a, t_stack *b, int nb, char s)
{
	if (s == 'a')
	{
		while (a->array[a->size - 1] != nb && ft_find_new_b(b, nb) > 0)
			ft_rrr(a, b);
		while (a->array[a->size - 1] != nb)
			ft_rra(a);
		while (ft_find_new_b(b, nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (b->array[b->size - 1] != nb && ft_find_new_a(a, nb) > 0)
			ft_rrr(a, b);
		while (b->array[b->size - 1] != nb)
			ft_rrb(b);
		while (ft_find_new_a(a, nb) > 0)
			ft_rra(a);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * Rotates stack b and Reverse Rotates stack a
 * 
 * @param[in] a Reference to stack a
 * @param[in] b Reference to stack b
 * @param[in] nb The number to push
 * @param[in] s Char for selecting target stack
 * @return -1 to reduce moves on call function
*/
int	ft_apply_rrarb(t_stack *a, t_stack *b, int nb, char s)
{
	if (s == 'a')
	{
		while (a->array[a->size - 1] != nb)
			ft_rra(a);
		while (ft_find_new_b(b, nb) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_new_a(a, nb) > 0)
			ft_rra(a);
		while (b->array[b->size - 1] != nb)
			ft_rb(b);
		ft_pa(a, b);
	}
	return (-1);
}

/**
 * Rotates stack a and Reverse Rotates stack b
 * 
 * @param[in] a Reference to stack a
 * @param[in] b Reference to stack b
 * @param[in] nb The number to push
 * @param[in] s Char for selecting target stack
 * @return -1 to reduce moves on call function
*/
int	ft_apply_rarrb(t_stack *a, t_stack *b, int nb, char s)
{
	if (s == 'a')
	{
		while (a->array[a->size - 1] != nb)
			ft_ra(a);
		while (ft_find_new_b(b, nb) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_new_a(a, nb) > 0)
			ft_ra(a);
		while (b->array[b->size - 1] != nb)
			ft_rrb(b);
		ft_pa(a, b);
	}
	return (-1);
}
