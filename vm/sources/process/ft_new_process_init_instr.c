/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process_init_instr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:13:14 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/10 23:54:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void		ft_vm_new_process_init_instr(t_vm *vm, t_process *new)
{
	extern t_op			g_op_tab[17];

	(void)vm;
	if (REG_IS_VALID(*new->pc))
		new->exec_cycle += g_op_tab[*new->pc].nb_cycles;
	else
		new->exec_cycle += 1;
	new->next_op = *new->pc;
	#if 0
	extern t_op			g_op_tab[17];

	ft_instruction_decode(vm, new);
	if (!new->instr)
		new->exec_cycle += 1;
	else
		new->exec_cycle += g_op_tab[*new->pc].nb_cycles;
	#endif
}
