/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:29:15 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/21 20:13:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief           Parse arguments
*
* param dead_pool		t_dead_pool struct for te game
* param av				Arguments' list
*/

void 			ft_vm_parse(t_dead_pool *dead_pool, char **av)
{
    ft_vm_parse_log(dead_pool, av);
    ft_vm_parse_start_c(dead_pool, av);
    ft_vm_parse_dump(dead_pool, av);
    ft_vm_parse_champion(dead_pool, av);
    //ft_vm_parse_help	//--help
}
