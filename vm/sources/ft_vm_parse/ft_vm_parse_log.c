/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_log.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:56:06 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 18:26:27 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

/*
* brief           Parse the --log option from arguments
*
* param dead_pool    t_dead_pool struct for the game
* param av        Arguments' list
*/


void		ft_vm_parse_log(t_dead_pool *dead_pool, char **av)
{
	while (*av)
	{
		if (!ft_strcmp("--log", *av))
		{
			dead_pool->option.log = 1;
			ft_log_open("logfile.txt");
			break ;
		}
		++av;
	}
}
