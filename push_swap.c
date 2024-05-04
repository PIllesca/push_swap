/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:31:35 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 00:10:30 by pillesca         ###   ########.fr       */
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
 * Debug only, shows the numbers contained in the stack
 * 
 * @param[in] stack Stack to print
*/
static void	ft_print_stacks(t_stack	*stack_a, t_stack *stack_b)
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
	if (ft_chk_sorted(stack_a))
		ft_putstr_fd("Is sorted.\n", 1);
	else
		ft_putstr_fd("Is unsorted.\n", 1);
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
}
