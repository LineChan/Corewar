/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_pc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:49:28 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/17 14:25:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"
#include <unistd.h>

void			ft_vm_display_pc(t_vm const *vm,
								t_process const *proc,
								t_instr const *instr)
{
	size_t		i;

	i = 0;
	ft_printf("ADV %d (%#0.4x -> %#0.4x) ", instr->new_pc - proc->pc, proc->pc - vm->arena[0],
					instr->new_pc - vm->arena[0]);
	while (i < (size_t)(instr->new_pc - proc->pc))
	{
		ft_printf("%02hhx ", *(proc->pc + i));
		++i;
	}
	write(1, "\n", 1);
}
