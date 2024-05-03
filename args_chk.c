/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:31 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/03 19:06:44 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

static int	ft_chk_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	else
	{
		while (*str)
		{
			if (ft_isdigit(*str))
				str++;
			else
				return (-1);
		}
	}
	return (0);
}

void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

static void	ft_chk_string(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '-' || *str == '+')
		{
			str++;
		}
		else
		{
			if (ft_isdigit(*str))
				str++;
			else
				ft_error_exit();
		}
	}
}

int	ft_chk_args(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		ft_chk_string(argv[1]);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_chk_digit(argv[i]) == -1)
				ft_error_exit();
			i++;
		}
	}
	return (0);
}
