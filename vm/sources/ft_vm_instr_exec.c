/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:32:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/03 14:34:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

// TODO : presentation
static int ft_vm_instr_tmp(unsigned char arena[], t_champion *champ)
{
	(void)champ;
	(void)arena;
	ft_printf("{red: function not written yet}\n");
	return (EXIT_FAILURE);
}

static const		t_instr_list g_instr_list [] =
{
	{0},
	{&ft_vm_instr_tmp}, //1
	{&ft_vm_instr_tmp}, //2
	{&ft_vm_instr_st},  //3
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
	DEBUG_MODE ? ft_printf("{yellow:instr_exec in}\n") : 0;
	DEBUG_MODE ? ft_printf("champ->instr.op->numero : {green:%d}\n", champ->instr.op->numero) : 0;
	if ((champ->instr.op->numero > 0) && (champ->instr.op->numero < 17))
	{
		if (g_instr_list[champ->instr.op->numero].func(arena, champ) == EXIT_SUCCESS)
			{
				//NOTE : be careful when end of the memory etc
				// PC = (PC + size) % MEM_SIZE
				//ft_printf("jump[0] : %d jump[1] : %d jump[2] : %d\n", champ->instr.arg_jump[0], champ->instr.arg_jump[1], champ->instr.arg_jump[2]);

				//champ->pc += (champ->instr.arg_jump[0] + champ->instr.arg_jump[1] + champ->instr.arg_jump[2] + 1);
				ft_memset((void *)&champ->instr, 0, sizeof(t_vm_instr));


			}
		else
			champ->pc += 1;
	}
	else
		champ->pc += 1;
	#if 0
	if ((champ->pc - arena) == champ->header.prog_size)
	{
		champ->pc -= champ->header.prog_size;
		ft_printf("end of program !");
	}
	#endif
	ft_printf("{yellow:instr_exec out}\n");

}
