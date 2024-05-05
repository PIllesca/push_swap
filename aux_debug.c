/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:18:14 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 00:21:27 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Debug only, shows in any memory leaks in macos terminal
*/
void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

/**
 * Debug only, shows the numbers contained in the stack
 * 
 * @param[in] stack Stack to print
*/
void	ft_print_stacks(t_stack	*stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	k;

	i = stack_a->size;
	j = stack_b->size;
	if (i > j)
		k = i;
	else
		k = j;
	while (k--)
	{
		i--;
		j--;
		if (i >= 0)
			ft_putnbr_fd(stack_a->array[i], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(' ', 1);
		if (j >= 0)
			ft_putnbr_fd(stack_b->array[j], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
	}
}
