/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:32:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/15 00:11:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

// TODO : presentation
//TODO : remove libc
# include <libc.h>

static void ft_vm_instr_tmp(unsigned char arena[],
							t_dead_pool *dead_pool)
{
	(void)arena;
	(void)dead_pool;
	ft_printf("{red: function not written yet}\n");
}

static const		t_instr_list g_instr_list [] =
{
	{0},
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
	{&ft_vm_instr_fork}, // ----> fork
	{&ft_vm_instr_lld},
	{&ft_vm_instr_lldi},
	{&ft_vm_instr_tmp}, // ---> lfork
	{&ft_vm_instr_aff},
};

void			ft_vm_instr_exec(unsigned char arena[], t_dead_pool *dead_pool)
{
	ft_printf("\t{bblack:ft_vm_instr_exec} {green:in} op : %hhx\n", dead_pool->champ[CHAMP_IDX].instr.op->numero);
	g_instr_list[dead_pool->champ[CHAMP_IDX].instr.op->numero].func(arena, dead_pool);
	dead_pool->champ[CHAMP_IDX].next_cycle += dead_pool->champ[CHAMP_IDX].instr.op->nb_cycles;
	ft_printf("\t{bblack:ft_vm_instr_exec} {green:out}\n");
}
