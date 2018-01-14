/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:08:42 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:24:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO:libs
#include "ft_printf.h"
void			ft_vm_parse_n(t_vm *vm)
{
	#if 0
	*vm->option.next_arg = ft_atoi(*vm->option.av);
	++vm->option.av;
	--vm->option.ac;
	vm->option.next_arg = 0;
	vm->option.state = OPT_STATE_CHAMPION;
	#endif
	int			n;

	++vm->option.av;
	--vm->option.ac;
	n = ft_atoi(*vm->option.av);
	/* Check if the process' number is valid */
	if ((n < 1) || (n > MAX_PLAYERS) || vm->fd[n - 1])
		ft_exit("Wrong champion's number");
	++vm->option.av;
	--vm->option.ac;
	/* Set the next_arg on the option's structure */
	vm->option.next_arg = &vm->fd[n - 1];
	/* Set the next state to get the process' file */
	vm->option.state = OPT_STATE_CHAMPION;
}
