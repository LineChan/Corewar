/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_lldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:55:45 by mvillemi          #+#    #+#             */
/*   Updated: 2018/02/02 22:37:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_display_lldi(t_proc const *proc)
{
	ft_printf("P %4d | lldi %d %d r%d\n",
					-proc->proc_nb,
					proc->instr->args[0].data,
					proc->instr->args[1].data,
					proc->instr->args[2].data);
	ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
					proc->instr->args[0].data,
					proc->instr->args[1].data,
					proc->instr->args[0].data + proc->instr->args[1].data,
					proc->pc +
					proc->instr->args[0].data + proc->instr->args[1].data);
}
