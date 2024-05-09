/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:22:04 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 13:26:59 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Debug only, shows any memory leaks in macos terminal
*/
void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	ft_print_stacks(t_stack *s_a, t_stack *s_b)
{
	ft_putendl_fd("A\tB", 1);
	while (s_a || s_b)
	{
		if (s_a)
		{
			ft_putnbr_fd(s_a->nb, 1);
			s_a = s_a->next;
		}
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\t', 1);
		if (s_b)
		{
			ft_putnbr_fd(s_b->nb, 1);
			s_b = s_b->next;
		}
		ft_putchar_fd('\n', 1);
	}
}
