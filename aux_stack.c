/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:17:02 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 15:24:16 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

t_stack	*ft_create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_error_exit();
	stack->array = (int *)malloc(size * sizeof(int));
	if (stack->array == NULL)
		ft_error_exit();
	stack->size = 0;
	return (stack);
}

void	ft_destroy_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

void	ft_push_stack(t_stack *stack, int nb)
{
	stack->array[stack->size] = nb;
	stack->size++;
}

int	ft_pop_stack(t_stack *stack)
{
	if (stack->size > 0)
	{
		stack->size--;
		return (stack->array[stack->size]);
	}
	return (0);
}

void	ft_swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[stack->size - 1];
		stack->array[stack->size - 1] = stack->array[stack->size - 2];
		stack->array[stack->size - 2] = tmp;
	}
}
