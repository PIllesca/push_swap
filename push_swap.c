/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:24:56 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 17:32:18 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

static void ft_push_sort(t_stack **s_a, t_stack **s_b)
{
	t_move	move;

	while (ft_stack_size(*s_a) > 3 && !ft_chk_sorted(*s_a))
	{
		move = ft_best_ab_rotation(*s_a, *s_b);
		if (move.rotation == rarb)
			ft_apply_rarb(s_a, s_b, move);
		else if (move.rotation == rrarrb)
			ft_apply_rrarrb(s_a, s_b, move);
		else if (move.rotation == rarrb)
			ft_apply_rarrb(s_a, s_b, move);
		else if (move.rotation == rrarb)
			ft_apply_rrarb(s_a, s_b, move);
	}
}

static void	ft_sort_stack(t_stack **s_a, t_stack **s_b)
{
	ft_print_stacks(*s_a, *s_b);
	if (ft_stack_size(*s_a) == 2)
		ft_sa(s_a);
	else
	{
		if (ft_stack_size(*s_a) > 3 && !ft_chk_sorted(*s_a))
			ft_pb(s_a, s_b);
		if (ft_stack_size(*s_a) > 3 && !ft_chk_sorted(*s_a))
			ft_pb(s_a, s_b);
		if (ft_stack_size(*s_a) > 3 && !ft_chk_sorted(*s_a))
			ft_push_sort(s_a, s_b);
		if (ft_stack_size(*s_a) == 3 && !ft_chk_sorted(*s_a))
			ft_sort_three(s_a);
	}
	ft_print_stacks(*s_a, *s_b);
}

/**
 * Currently incomplete, main function
 * Initiates both stacks, fills stack a with the executable input and checks 
 * if it is already sorted. If it isn't sorted calls the function ft_sort_stack
 * 
 * @param[in] argc Number of arguments
 * @param[in] argv String array input
 * @param[in] c Size of the stacks
*/
void	ft_push_swap(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_init_stack(argc, argv);
	stack_b = NULL;
	if (!ft_chk_sorted(stack_a))
		ft_sort_stack(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
