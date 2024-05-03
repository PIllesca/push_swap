/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:17:20 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/03 12:42:00 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	ft_chk_args(int argc, char *argv[])
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc < 4)
	{
		ft_putstr_fd("Error\n", 1);
	}
	else
	{
		ft_putstr_fd(argv[1], 1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	ft_chk_args(argc, argv);
	return (0);
}
