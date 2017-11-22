/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:39:02 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/21 20:21:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief           Parse the -dump=nb option from arguments
*
* param dead_pool    t_dead_pool struct for the game
* param av        Arguments list
*/

void			ft_vm_parse_dump(t_dead_pool *dead_pool, char **av)
{
	while (*av)
	{
		if (!ft_strncmp("-dump", *av, 5))
		{
			if (*(*av + 5) == '=')
			{
				if (IS_NEG((dead_pool->option.dump = ft_atoi(*av + 6))))
					EXIT_FAIL("Error : -dump takes a positive integer");
			}
			else if (*(*av + 5) == '\0')
			{
				if (!*(av + 1) || IS_NEG((dead_pool->option.dump = ft_atoi(*(av + 1)))))
					EXIT_FAIL("Error : -dump takes a positive integer");
			}
			else
				EXIT_FAIL("Error : did you mean -dump=nb ?");
		}
		++av;
	}
}
