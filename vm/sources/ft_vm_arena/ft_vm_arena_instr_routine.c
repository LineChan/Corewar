/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_instr_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:50:51 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 18:25:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      			Execute a routine for each instruction
*
* param arena			Memory dedicated to the Virtual Machine
* param dead_pool		t_dead_pool struct for the game
* param nb_champion		Number of alive champions in the arena
*/
static const		t_instr_list g_instr_list [] =
{
	{0},
	#if 0
	{&ft_vm_instr_live},
	{&ft_vm_instr_ld},
	{&ft_vm_instr_st},
	{&ft_vm_instr_add},
	{&ft_vm_instr_sub},
	{&ft_vm_instr_and},
	{&ft_vm_instr_or},
	{&ft_vm_instr_xor},
	{&ft_vm_instr_zjmp},
	{&ft_vm_instr_ldi},
	{&ft_vm_instr_sti},
	{&ft_vm_instr_fork},
	{&ft_vm_instr_lld},
	{&ft_vm_instr_lldi},
	{&ft_vm_instr_lfork},
	{&ft_vm_instr_aff},
	#endif
};

void			ft_vm_arena_instr_routine(unsigned char arena[2][MEM_SIZE],
											t_dead_pool *dead_pool,
											t_champion *i_champ)
{
	if ((*i_champ->pc == 0) || (*i_champ->pc > INSTR_NUMBER))
	{
		ft_vm_instr_fail(i_champ, !CARRY_CHANGE);
		return ;
	}
	/* Copy all the information concerning the instruction */
	i_champ->instr.op = &g_op_tab[*i_champ->pc];
	/* Read the bytecode if there is one */
	if (i_champ->instr.op->param_byte)
	{
		i_champ->instr.bytecode = (unsigned int)*(i_champ->pc + 1);
		/* Save the argument type of the instruction and their size*/
		if (ft_vm_instr_jump(i_champ) == EXIT_FAILURE)
		{
			ft_vm_instr_fail(i_champ, !CARRY_CHANGE);
			return ;
		}
	}
	/* Execute a function thanks to the lookup table above*/
	g_instr_list[i_champ->instr.op->numero].func(arena, dead_pool, i_champ);
	//ft_vm_notif_instr()
}
