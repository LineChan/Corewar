/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:32:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/02 10:23:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

// TODO : presentation
static void ft_vm_instr_tmp(unsigned char arena[], t_champion *champ)
{
	(void)champ;
	(void)arena;
	ft_printf("{red: function not written yet}\n");
}

static const		t_instr_list g_instr_list [] =
{
	{0},
	{&ft_vm_instr_tmp}, //1
	{&ft_vm_instr_tmp}, //2
	{&ft_vm_instr_tmp}, //3
	{&ft_vm_instr_tmp}, //4
	{&ft_vm_instr_tmp}, //5
	{&ft_vm_instr_tmp}, //6
	{&ft_vm_instr_tmp}, //7
	{&ft_vm_instr_tmp}, //8
	{&ft_vm_instr_tmp}, //9
	{&ft_vm_instr_tmp}, //10
	{&ft_vm_instr_sti}, //11
	{&ft_vm_instr_tmp}, //12
	{&ft_vm_instr_tmp}, //13
	{&ft_vm_instr_tmp}, //14
	{&ft_vm_instr_tmp}, //15
	{&ft_vm_instr_tmp}, //16
};
void			ft_vm_instr_exec(unsigned char arena[], t_champion *champ)
{
	ft_printf("instr exec\n");
	if (champ->instr.op->numero <= 16)
		g_instr_list[champ->instr.op->numero].func(arena, champ);
	else
		champ->pc += 1;
}
