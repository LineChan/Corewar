/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_start_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:00:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/21 11:49:58 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief           Parse the -start_c=nb option from arguments
*
* param option    t_dead_pool struct for the game
* param ac        Number of arguments
* param av        Arguments list
*/

void			ft_vm_parse_start_c(t_dead_pool *dead_pool, int ac, char **av)

{
	while (ac)
	{
		ft_printf("start_c : %s\n", *av);
		if (!ft_strncmp("-start_c", *av, 8))
		{
			if (*(*av + 8) == '=')
			{
				if (IS_NEG((dead_pool->option.start_c = ft_atoi(*av + 9))))
					EXIT_FAIL("Error : -start_c takes a positive integer");
			}
			else if (*(*av + 8) == '\0')
			{
				if (!*(av + 1) || IS_NEG((dead_pool->option.start_c = ft_atoi(*(av + 1)))))
				EXIT_FAIL("Error : -start_c takes a positive integer");
			}
			else
			EXIT_FAIL("Error : did you mean -start_c=nb ?");
		}
		++av;
		--ac;
	}
}
