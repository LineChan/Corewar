/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_display_st.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:09:17 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/13 11:29:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_display_st(t_vm *vm,
								t_process const *proc,
								t_instr const *instr)
{
	if (DISPLAY_4)
	{
		ft_printf("P    %d | st r%d %d\n",
				proc->parent_nb,
				instr->args[0].data,
				instr->args[1].data);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
}
