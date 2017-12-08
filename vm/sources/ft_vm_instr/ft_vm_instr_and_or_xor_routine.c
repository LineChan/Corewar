/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and_or_xor_routine.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:37:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/07 23:30:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs

#include "ft_printf.h"
int			ft_vm_instr_and_or_xor_routine(t_vm *vm, t_process *proc,
											unsigned char **ptr,
											int tab[2])
{
	int					i;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	i = 0;
	/* Set up the pointer at the beginning of the arguments */
	*ptr = proc->pc + 2;
	/* Read arguments */
	while (i < (proc->op->nb_args - 1))
	{
		if (proc->op->arg_types[i] == T_REG)
		{
			if (!IS_REG(**ptr))
			{
				ft_vm_instr_fail(vm, proc,
					2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
					CARRY_CHANGE);
					return (EXIT_FAILURE);
			}
				tab[i] = proc->reg[**ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
		{
			tab[i] = ft_vm_instr_get_data(REG_SIZE,
				&vm->arena[0][MOD(ft_vm_instr_get_data(2, *ptr, vm))], vm);
				#if 0
				&vm->arena[0][MOD(proc->pc - vm->arena[0]
					+ ft_vm_instr_get_data(2, *ptr))]);
					#endif
		}
		else
		{
			tab[i] = ft_vm_instr_get_data(
				g_direct_jump_table_from_instr[proc->op->numero], *ptr, vm);
		}
		*ptr += proc->jump[i];
		++i;
	}
	if (!IS_REG(**ptr))
	{
		ft_vm_instr_fail(vm, proc,
			2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
			CARRY_CHANGE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
