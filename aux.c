/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:35:33 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 13:29:34 by pillesca         ###   ########.fr       */
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
 * Exits the program with an error message
 * 
 * @param[in] s_a Stack to free
*/
void	ft_error_exit(t_stack *s_a)
{
	if (s_a)
		ft_free_stack(s_a);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
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
 * Checks if the stack is sorted
 * 
 * @param[in] stack Stack to check
 * @returns 1 if sorted, 0 if not
*/
int	ft_chk_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
