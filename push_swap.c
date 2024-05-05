/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:31:35 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 18:07:14 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Fills the stack with the executable input
 * 
 * @param[in] stack Stack to fill
 * @param[in] argc Number of arguments
 * @param[in] argv String array input
*/
static void	ft_fill_stack(t_stack	*stack, int argc, char *argv[], int c)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	j = c;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i] && j--)
	{
		stack->array[j] = ft_atoi(args[i]);
		stack->size++;
		i++;
	}
	if (argc == 2)
		ft_free_str(args);
}

/**
 * Once we have a minimum and maximum as base we sort and push everything to 
 * stack b until we have everything sorted in stack a or a has reached a size 
 * of three
 * 
 * @param[in] stack_a Reference to Stack a
 * @param[in] stack_b Reference to Stack b
*/
void	ft_push_sort(t_stack *a, t_stack *b)
{
	int	index;
	int	moves;

	while (a->size > 3 && !ft_chk_sorted(a))
	{
		index = a->size - 1;
		moves = ft_best_ab_rotation(a, b);
		while (moves >= 0)
		{
			if (moves == ft_case_rarb(a, b, a->array[index]))
				moves = ft_apply_rarb(a, b, a->array[index], 'a');
			else if (moves == ft_case_rrarrb(a, b, a->array[index]))
				moves = ft_apply_rrarrb(a, b, a->array[index], 'a');
			else if (moves == ft_case_rarrb(a, b, a->array[index]))
				moves = ft_apply_rarrb(a, b, a->array[index], 'a');
			else if (moves == ft_case_rrarb(a, b, a->array[index]))
				moves = ft_apply_rrarb(a, b, a->array[index], 'a');
			else
				index--;
		}
	}
}

void	ft_pop_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_print_stacks(stack_a, stack_b);
}

/**
 * Sorts the stacks, if stack a is unsorted and of size two we swap a. 
 * Otherwise while stack a remains unsorted and bigger than size three we move 
 * everything to b. The first two elements for a maximum and minimum and the 
 * rest we move already sorted using those as a base. Once everything we need 
 * to move is in b we check to see if we need to sort the last three elements
 * 
 * @param[in] stack_a Reference to Stack a
 * @param[in] stack_b Reference to Stack b
*/
void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		ft_sa(stack_a);
	else
	{
		if (stack_a->size > 3 && !ft_chk_sorted(stack_a))
			ft_pb(stack_a, stack_b);
		if (stack_a->size > 3 && !ft_chk_sorted(stack_a))
			ft_pb(stack_a, stack_b);
		if (stack_a->size > 3 && !ft_chk_sorted(stack_a))
			ft_push_sort(stack_a, stack_b);
		if (!ft_chk_sorted(stack_a))
			ft_sort_three(stack_a);
		if (stack_b->size > 0)
			ft_pop_sort(stack_a, stack_b);
	}
}

/**
 * Currently incomplete, main function
 * 
 * @param[in] argc Number of arguments
 * @param[in] argv String array input
 * @param[in] c Size of the stacks
*/
void	ft_push_swap(int argc, char *argv[], int c)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_create_stack(c);
	stack_b = ft_create_stack(c);
	ft_fill_stack(stack_a, argc, argv, c);
	ft_print_stacks(stack_a, stack_b);
	if (!ft_chk_sorted(stack_a))
		ft_sort_stack(stack_a, stack_b);
	ft_print_stacks(stack_a, stack_b);
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
}
