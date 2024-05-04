/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:31 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 17:23:02 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Checks if the passed string contains only digits and + - signs
 * 
 * @param[in] str String to check
 * @returns 0 on valid string -1 on invalid string
*/
static int	ft_chk_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (-1);
	}
	return (0);
}

/**
 * Checks if the passed number is bigger than an int and checks if it
 *  repeats somewhere else on the string array
 * 
 * @param[in] nb Original number to compare to
 * @param[in] args String array to check against
 * @param[in] i Index to where in the array to start checking
 * @returns 0 on valid non repeat number -1 on invalid input
*/
static int	ft_chk_repeat(long nb, char **args, int i)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (-1);
	i++;
	while (args[i])
	{
		if (ft_atol(args[i]) == nb)
			return (-1);
		i++;
	}
	return (0);
}

/**
 * Controlled error exit, checks if there is a need to free the result of an
 * ft_split and if so proceeds to free the memory.
 * 
 * @param[in] args String array that may need freeing
 * @param[in] argc Arguments amount if 2 we need to free the memory
*/
static void	ft_error(char **args, int argc)
{
	if (argc == 2)
		ft_free_str(args);
	ft_error_exit();
}

/**
 * Checks if the executable arguments are valid
 * 
 * @param[in] argc Number of arguments
 * @param[in] argv String array input
 * @returns The amount of numbers found in the executable arguments
*/
int	ft_chk_args(int argc, char *argv[])
{
	int		i;
	long	tmp;
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
		tmp = ft_atol(args[i]);
		if (ft_chk_digit(args[i]) < 0 || ft_chk_repeat(tmp, args, i) < 0)
			ft_error(args, argc);
		i++;
	}
	if (argc == 2)
		ft_free_str(args);
	if (i < 2)
		ft_error_exit();
	return (i);
}
