/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_live.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:49:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/11 00:57:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

static void		ft_vm_display_instr(t_process const *proc,
									t_list const *it,
									const int nb)
{
	if (it)
	{
		ft_printf("P    %d | live %d\n", proc->parent_nb,
									C_PROCESS(it)->process_nb);
	}
	else
	{
		ft_printf("P    %d | live %d\n", proc->parent_nb, nb);
	}
}

static void			ft_vm_display_alive(t_vm *vm, t_list const *it)
{
	if (!it)
		return ;
	ft_printf("Player %d (%s) is said to be alive\n",
				C_PROCESS(it)->parent_nb,
				vm->header[C_PROCESS(it)->parent_nb - 1].prog_name);
}

static void			ft_vm_display_new_death(t_vm *vm,
											t_process const *proc)
{
	vm->option.death[-proc->process_nb - 1] = vm->current_cycle;
}

void			ft_vm_display_live(t_vm *vm,
									t_process const *proc,
									t_list const *it,
									const int nb)
{
	extern int8_t	g_direct_jump_table_from_instr[17];

	if (DISPLAY_4)
		ft_vm_display_instr(proc, it, nb);
	if (DISPLAY_1)
		ft_vm_display_alive(vm, it);
	if (DISPLAY_8)
		ft_vm_display_new_death(vm, proc);
	if (DISPLAY_16)
	{
		ft_vm_display_pc(vm, proc,
			1 + g_direct_jump_table_from_instr[proc->op->numero]);
	}
}
