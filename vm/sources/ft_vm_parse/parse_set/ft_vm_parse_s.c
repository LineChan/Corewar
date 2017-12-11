/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 23:31:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 23:39:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_parse_s(t_vm *vm)
{
	vm->option.next_arg = &vm->option.s;
	vm->option.state = OPT_STATE_NUMBER;
	++vm->option.av;
	--vm->option.ac;
	if (0 == vm->option.ac)
		ft_exit("Parsing error near -s");
}
