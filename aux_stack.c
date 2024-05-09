/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:25:38 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 14:35:10 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Creates a new node for the stack
 * 
 * @param[in] nb Number to store in the node
 * @param[in] s_a Stack to free in case of error
 * @returns New node
*/
static t_stack	*ft_new_node(int nb, t_stack *s_a)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error_exit(s_a);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

/**
 * Initializes the stack with the input arguments
 * 
 * @param[in] argc Number of arguments
 * @param[in] argv String array input
 * @returns Initialized stack 
*/
t_stack	*ft_init_stack(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;
	char	**args;

	i = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 2;
		args = argv;
	}
	stack_a = ft_new_node(ft_atoi(args[i - 1]), NULL);
	tmp = stack_a;
	while (args[i])
	{
		tmp->next = ft_new_node(ft_atoi(args[i]), stack_a);
		tmp = tmp->next;
		i++;
	}
	if (argc == 2)
		ft_free_str(args);
	return (stack_a);
}

/**
 * Frees the memory from a stack
 * 
 * @param[in] s_a Stack to free
*/
void	ft_free_stack(t_stack *s_a)
{
	t_stack	*tmp;

	while (s_a)
	{
		tmp = s_a;
		s_a = s_a->next;
		free(tmp);
	}
}

/**
 * Finds the index of nb if it was in stack b
 * 
 * @param[in] stack_b Reference to stack b
 * @param[in] nb Number to search
 * @returns Index of nb in b
*/
int	ft_find_new_b(t_stack *stack_b, int nb)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nb > stack_b->nb && nb < ft_find_last(stack_b)->nb)
		i = 0;
	else if (nb > ft_find_max(stack_b) || nb < ft_find_min(stack_b))
		i = ft_find_index(stack_b, ft_find_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nb < nb || tmp->nb > nb)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

/**
 * Finds the index of nb if it was in stack a
 * 
 * @param[in] stack_a Reference to stack a
 * @param[in] nb Number to search
 * @returns Index of nb in a
*/
int	ft_find_new_a(t_stack *stack_a, int nb)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nb < stack_a->nb && nb > ft_find_last(stack_a)->nb)
		i = 0;
	else if (nb > ft_find_max(stack_a) || nb < ft_find_min(stack_a))
		i = ft_find_index(stack_a, ft_find_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nb > nb || tmp->nb < nb)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
