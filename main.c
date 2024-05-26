/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:17:20 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 19:16:45 by pillesca         ###   ########.fr       */
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
	if (argc < 2)
		exit(EXIT_FAILURE);
	ft_chk_args(argc, argv);
	ft_push_swap(argc, argv);
	exit(EXIT_SUCCESS);
}
