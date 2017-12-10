/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:09:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 20:43:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <fcntl.h>
#include "ft_printf.h"

void			ft_vm_parse_number(t_vm *vm)
{
	if (IS_NEG((*vm->option.next_arg = ft_atoi(*vm->option.av))))
		ft_exit("Can't read the file");
	++vm->option.av;
	--vm->option.ac;
	vm->option.state = OPT_STATE_DEFAULT;
}
