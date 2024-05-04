/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:31 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 17:03:21 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

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

static void	ft_error(char **args, int argc)
{
	if (argc == 2)
		ft_free_str(args);
	ft_error_exit();
}

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
