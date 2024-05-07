/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:13:52 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/07 19:21:46 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Finds what index the number nb should get when pushed into stack b
 * 
 * @param[in] stack_b Reference to stack b
 * @param[in] nb The number to find the new index to
 * @returns The new index of nb in stack b
*/
int	ft_find_new_b(t_stack *stack_b, int nb)
{
	int		rtn;
	int		index;

	rtn = 1;
	index = stack_b->size - 1;
	if (nb > stack_b->array[index] && nb < stack_b->array[0])
		rtn = 0;
	else if (nb > ft_find_max(stack_b) || nb < ft_find_min(stack_b))
		rtn = ft_find_index(stack_b, ft_find_max(stack_b));
	else
	{
		while (stack_b->array[index] < nb || stack_b->array[index - 1] > nb)
		{
			index--;
			rtn++;
		}
	}
	return (rtn);
}

/**
 * Finds what index the number nb should get when pushed into stack a
 * 
 * @param[in] stack_a Reference to stack b
 * @param[in] nb The number to find the new index to
 * @returns The new index of nb in stack b
*/
int	ft_find_new_a(t_stack *stack_a, int nb)
{
	int		rtn;
	int		index;

	rtn = 1;
	index = stack_a->size - 1;
	if (nb < stack_a->array[index] && nb > stack_a->array[0])
		rtn = 0;
	else if (nb > ft_find_max(stack_a) || nb < ft_find_min(stack_a))
		rtn = ft_find_index(stack_a, ft_find_max(stack_a));
	else
	{
		while (stack_a->array[index] > nb || stack_a->array[index - 1] < nb)
		{
			index--;
			rtn++;
		}
	}
	return (rtn);
}
