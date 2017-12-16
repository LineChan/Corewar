/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:08:42 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 20:42:21 by mvillemi         ###   ########.fr       */
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
	if ((n < 1) || (n > MAX_PLAYERS) || vm->fd[n - 1])
		ft_exit("Wrong champion's number");
	++vm->option.av;
	--vm->option.ac;
	vm->option.next_arg = &vm->fd[n - 1];
	vm->option.state = OPT_STATE_CHAMPION;
}
