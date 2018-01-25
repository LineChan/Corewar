/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_aff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:30:11 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 01:04:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_instr_aff(t_vm *vm, t_proc *proc)
{
	if (vm->opt.display_aff == 1)
		ft_printf("%c\n", proc->reg[proc->instr->args[0].data] % 256);
	/* Display additional informations */
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
