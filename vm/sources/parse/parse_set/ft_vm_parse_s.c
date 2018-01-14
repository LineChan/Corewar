/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 23:31:43 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:28:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_parse_s(t_vm *vm)
{
	/* Set the next_arg on the option's structure */
	vm->option.next_arg = &vm->option.s;
	/* Set the next state to get the s value */
	vm->option.state = OPT_STATE_NUMBER;
	++vm->option.av;
	--vm->option.ac;
	/* An error occurs if there is no argument left */
	if (0 == vm->option.ac)
		ft_exit("Parsing error near -s");
}
