/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:31:35 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 17:36:23 by pillesca         ###   ########.fr       */
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
static void	ft_fill_stack(t_stack	*stack, int argc, char *argv[])
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		ft_push_stack(stack, ft_atoi(args[i]));
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
static void	ft_print_stack(t_stack	*stack)
{
	int	i;

	i = stack->size;
	while (i--)
	{
		ft_putnbr_fd(stack->array[i], 1);
		ft_putchar_fd('\n', 1);
	}
	ft_putchar_fd('\n', 1);
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
	ft_fill_stack(stack_a, argc, argv);
	ft_print_stack(stack_a);
	ft_rotate_stack(stack_a);
	ft_print_stack(stack_a);
	ft_inv_rotation(stack_a);
	ft_print_stack(stack_a);
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
}
