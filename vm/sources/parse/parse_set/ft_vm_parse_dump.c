/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 23:16:43 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:22:42 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_parse_dump(t_vm *vm)
{
	/* Set the next_arg on the options' structure */
	vm->option.next_arg = &vm->option.dump;
	/* Set the next state to get the display value */
	vm->option.state = OPT_STATE_NUMBER;
	++vm->option.av;
	--vm->option.ac;
	/* An error occurs if there si no argument left */
	if (0 == vm->option.ac)
		ft_exit("Parsing error near -dump");
}
