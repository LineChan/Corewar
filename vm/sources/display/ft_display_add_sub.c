/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_add_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:18:57 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 16:09:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void				ft_display_add_sub(t_proc const *proc)
{
	ft_printf("P %4d | %s r%d r%d r%d\n",
		-proc->proc_nb,
		proc->instr->op->name,
		proc->instr->args[0].data,
		proc->instr->args[1].data,
		proc->instr->args[2].data);
}
