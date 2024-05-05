/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:17:20 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/05 00:19:23 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Body of the executable
 * 
 * @param[in] argc Number of arguments
 * @param[in] argv String array input
*/
int	main(int argc, char *argv[])
{
	int	c;

	atexit(ft_leaks);
	if (argc < 2)
		exit(EXIT_FAILURE);
	c = ft_chk_args(argc, argv) - 1;
	if (argc == 2)
		c++;
	ft_push_swap(argc, argv, c);
	exit(EXIT_SUCCESS);
}
