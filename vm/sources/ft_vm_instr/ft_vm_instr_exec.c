/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:32:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/18 23:02:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
//TODO : remove libc
#include <libc.h>
#include "ft_log.h"

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
	{&ft_vm_instr_fork},
	{&ft_vm_instr_lld},
	{&ft_vm_instr_lldi},
	{&ft_vm_instr_lfork},
	{&ft_vm_instr_aff},
};

void			ft_vm_instr_exec(unsigned char arena[],
									t_dead_pool *dead_pool,
									int option[])
{
	ft_printf("\t{bblack:ft_vm_instr_exec} {green:in} op : %s --> %hhx\n", dead_pool->i_champ->header.prog_name, dead_pool->i_champ->instr.op->numero);
	ft_printf("op->numero : %d\n", dead_pool->i_champ->instr.op->numero);
	/* Look up table for the instruction */
	g_instr_list[dead_pool->i_champ->instr.op->numero].func(arena, dead_pool, option);
	ft_printf("\t{bblack:ft_vm_instr_exec} {green:out}\n");
}
