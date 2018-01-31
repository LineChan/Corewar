/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:49:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/31 13:48:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"
#include <unistd.h>

void		ft_display_pc(t_vm *vm, t_proc const *proc)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	if ((DISPLAY_32) && (proc->proc_nb == -proc->parent_nb))
		ft_visual_refresh_player(&vm->visual.player, proc);
	if (proc->instr->zjmp_success)
		return ;
	ft_printf("ADV %d (0x%04x -> 0x%04x) ", proc->instr->size, proc->pc, proc->pc + i);
	ptr = &vm->arena[proc->pc];
	while (i < proc->instr->size)
	{
		/* Print '00' if stealth mode is ON */
		if (0 != vm->opt.stealth)
			ft_printf("ff ");
		/* Else, print the correct byte */
		else
			ft_printf("%02hhx ", ft_arena_get_int8(vm, proc->pc + i));
		++i;
	}
	write(1, "\n", 1);
}
