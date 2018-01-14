/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:27:08 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:20:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "macro.h"
#include "ft_printf.h"

void			ft_vm_parse_display(t_vm *vm)
{
	/* Set the next_arg on the options' structure */
	vm->option.next_arg = &vm->option.display;
	/* Set the next state to get the display value */
	vm->option.state = OPT_STATE_NUMBER;
	++vm->option.av;
	--vm->option.ac;
	/* An error occurs if there is no argument left */
	if (0 == vm->option.ac)
		ft_exit("Parsing error near -display");
}
