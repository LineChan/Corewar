/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_log.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:18:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/24 13:27:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_string.h"

void 			ft_vm_parse_log(t_vm *vm, char **av)
{
	while (*av)
    {
        if (!ft_strcmp("--log", *av))
        {
            vm->option.log = 1;
            ft_log_open("logfile.txt");
        }
        ++av;
    }
}
