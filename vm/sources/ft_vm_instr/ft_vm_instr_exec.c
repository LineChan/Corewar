/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:32:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/11 15:30:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

// TODO : presentation
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
	{&ft_vm_instr_tmp}, // ----> fork
	{&ft_vm_instr_lld},
	{&ft_vm_instr_lldi},
	{&ft_vm_instr_tmp}, // ---> lfork
	{&ft_vm_instr_aff},
};
//TODO : remove libc
# include <libc.h>

void			ft_vm_instr_exec(unsigned char arena[], t_dead_pool *dead_pool)
{
	ft_printf("{yellow:instr_exec in}\n");
	DEBUG_MODE ? ft_printf("dead_pool->i_champ->instr.op->numero : {green:%d}\n", dead_pool->i_champ->instr.op->numero) : 0;
	static int i = 0;
	if ((*dead_pool->i_champ->pc > 0) && (*dead_pool->i_champ->pc <= INSTR_NUMBER))
	{
		ft_printf("next_cycle -------------> {green:in}: %d\n", dead_pool->i_champ->next_cycle);
		if (DEBUG_MODE)
			ft_printf("nb of instruction : %d\n", i);
		ft_printf("next_cycle -------------> {green:while1}: %d\n", dead_pool->i_champ->next_cycle);
		g_instr_list[dead_pool->i_champ->instr.op->numero].func(arena, dead_pool);
		ft_printf("next_cycle -------------> {green:while2}: %d\n", dead_pool->i_champ->next_cycle);
		ft_printf("cycle to add : %d \n", dead_pool->i_champ->instr.op->nb_cycles);
		dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
		ft_printf("next_cycle -------------> {green:out}: %d\n", dead_pool->i_champ->next_cycle);
		++i;
	}
	else
		dead_pool->i_champ->pc += 1;
	ft_printf("{yellow:instr_exec out}\n");

}
