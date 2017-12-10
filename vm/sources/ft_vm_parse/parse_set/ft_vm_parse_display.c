/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:27:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 20:43:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "macro.h"
#include "ft_printf.h"

void			ft_vm_parse_display(t_vm *vm)
{
	vm->option.next_arg = &vm->option.display;
	vm->option.state = OPT_STATE_NUMBER;
	++vm->option.av;
	--vm->option.ac;
	if (0 == vm->option.ac)
		ft_exit("Parsing error near -display");
}
