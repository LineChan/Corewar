/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_decode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:05:09 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 18:12:50 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

#include "ft_printf.h"
uint8_t			ft_instr_decode(t_vm *vm, t_proc *proc)
{
	uint8_t		bytecode;

	ft_printf("instr decode\n");
	/* Check if the OP code is valid */
	if (!OPCODE_IS_VALID(proc->next_op))
		return (OPCODE_NOT_VALID);
	/* Decode the bytecode */
	bytecode = ft_instr_setup(vm, proc);
	/* Parse instruction */
	return (ft_instr_parse(vm, proc, bytecode));
}
