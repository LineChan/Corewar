/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:09:52 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:26:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <fcntl.h>
#include "ft_printf.h"

void			ft_vm_parse_number(t_vm *vm)
{
	/* Options' values can't be negative, here the function checks */
	/* is the processes' File Descriptorsk are valid */
	if (IS_NEG((*vm->option.next_arg = ft_atoi(*vm->option.av))))
		ft_exit("Can't read the file");
	++vm->option.av;
	--vm->option.ac;
	/* Reset the State Machine to default */
	vm->option.state = OPT_STATE_DEFAULT;
}
