/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:51:46 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:00:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_string.h"
#include "macro.h"
#include <fcntl.h>

void 			ft_vm_parse_champion(t_vm *vm)
{

	static int					all_champions_found = 0;
	static unsigned int			current_i = 0;

	/* 4 Process have already been found */
	if (1 == all_champions_found)
		ft_exit("Too many champions want to fight");
	/* Processes's numbers can be chosen with the -n option. */
	/* If not, the File Descriptor is stored in a temporary array */
	if (0 == vm->option.next_arg)
		vm->option.next_arg = &vm->fd_tmp[current_i++];
	/* Check if the extension (.cor) is valid */
	if (!(*(int *)".cor" ==
		*(int *)(*vm->option.av + ft_strlen(*vm->option.av) - 4)))
		ft_exit("Extension .cor not found");
	/* Open the file */
	if (IS_NEG((*vm->option.next_arg = open(*vm->option.av, O_RDONLY, 0666))))
		ft_exit("The file can't be read");
	++vm->nb_champion;
	if (vm->nb_champion == MAX_PLAYERS)
		all_champions_found = 1;
	++vm->option.av;
	--vm->option.ac;
	/* Reset parameters for the State Machine */
	vm->option.next_arg = 0;
	vm->option.state = OPT_STATE_DEFAULT;
}
