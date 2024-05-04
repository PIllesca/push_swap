/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:17:20 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/04 12:27:50 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char *argv[])
{
	int	c;

	atexit(ft_leaks);
	if (argc < 2)
		exit(EXIT_FAILURE);
	c = ft_chk_args(argc, argv) - 1;
	if (argc == 2)
		c++;
	ft_putnbr_fd(c, 1);
	exit(EXIT_SUCCESS);
}
