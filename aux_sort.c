/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:42:13 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 17:45:24 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Finds the lowest number in the stack
 * 
 * @param[in] stack Stack to search
 * @returns Lowest number in the stack
*/
int	ft_find_min(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->array[i];
	while (i < stack->size)
	{
		if (tmp > stack->array[i])
			tmp = stack->array[i];
		i++;
	}
	return (tmp);
}

/**
 * Finds the highest number in the stack
 * 
 * @param[in] stack Stack to search
 * @returns Highest number in the stack
*/
int	ft_find_max(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->array[i];
	while (i < stack->size)
	{
		if (tmp < stack->array[i])
			tmp = stack->array[i];
		i++;
	}
	return (tmp);
}

/**
 * Finds nb number position in the stack
 * 
 * @param[in] stack Stack to search
 * @param[in] nb Number to find
 * @returns The index of the number nb
*/
int	ft_find_index(t_stack *stack, int nb)
{
	int	i;
	int	j;

	i = stack->size;
	j = 0;
	while (i--)
	{
		if (stack->array[i] == nb)
			return (j);
		j++;
	}
	return (j);
}

/**
 * Sorts a stack of 3 elements
 * 
 * @param[in] stack Stack to sort
*/
void	ft_sort_three(t_stack *stack)
{
	if (stack->array[2] == ft_find_min(stack))
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (stack->array[2] == ft_find_max(stack))
	{
		ft_ra(stack);
		if (!ft_chk_sorted(stack))
			ft_sa(stack);
	}
	else
	{
		if (stack->array[1] == ft_find_max(stack))
			ft_rra(stack);
		else
			ft_sa(stack);
	}
}
