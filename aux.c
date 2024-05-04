/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:29:40 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 00:09:34 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Same as atoi but for Long Integer
 * 
 * @param[in] str String to convert to long
 * @returns Converted long
*/
long	ft_atol(const char *str)
{
	long	i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

/**
 * Frees the memory from a ft_split
 * 
 * @param[in] str String array to free
*/
void	ft_free_str(char **str)
{
	char	**temp;

	temp = str;
	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free(str);
}

/**
 * Controlled error exit
*/
void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * Checks if the stack is already sorted
 * 
 * @param[in] stack Stack to check
 * @returns 1 if sorted, 0 if not
*/
int	ft_chk_sorted(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->size - 1;
	tmp = stack->array[i];
	while (i--)
	{
		if (tmp > stack->array[i])
			return (0);
		tmp = stack->array[i];
	}
	return (1);
}
