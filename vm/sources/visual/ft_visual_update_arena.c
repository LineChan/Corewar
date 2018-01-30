/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_update_arena.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:00:07 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/29 22:22:50 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_visual.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_visual_update_arena(t_vm *vm, t_proc const *proc)
{
	int		i;

	i = 0;
	while (i < proc->instr->size)
	{
		#if 0
		if (0 != vm->option.stealth)
			ft_printf("ff ");
		else
		#endif
		//ft_printf("%02hhx ", ft_arena_get_int8(vm->visual.arena, proc->pc + i));
		ft_printf("%02hhx ", vm->visual.arena[proc->pc + i]);
		++i;
	}
	vm->visual.pc_position[proc->pc] = 0;
	vm->visual.pc_position[proc->instr->new_pc] = proc->parent_nb;
}
