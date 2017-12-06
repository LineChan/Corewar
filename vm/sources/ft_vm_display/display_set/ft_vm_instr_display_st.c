/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_display_st.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:09:17 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/06 18:41:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void		ft_vm_display_st(t_vm *vm, t_process *proc)
{
		(void)vm;
		if (proc->op->arg_types[1] == T_REG)
		{
			ft_printf("P    %d | st r%d %d\n", proc->parent_nb,
			*(proc->pc + 2), *(proc->pc + 3));
		}
		else
		{
			ft_printf("P    %d | st r%d %d\n", proc->parent_nb,
			*(proc->pc + 2), ft_instruction_get_data(2, proc->pc + 3));
		}
}
