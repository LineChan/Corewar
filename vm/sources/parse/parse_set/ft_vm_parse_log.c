/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_log.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:18:20 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:23:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_string.h"

// TODO : remove parse_log
void 			ft_vm_parse_log(t_vm *vm)
{
	vm->option.log = 1;
	ft_log_open("logfile.txt");
	++vm->option.av;
	--vm->option.ac;
	vm->option.state = OPT_STATE_DEFAULT;
}
