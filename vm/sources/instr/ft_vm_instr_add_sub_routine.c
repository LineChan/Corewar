/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add_sub_routine.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:25:16 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/12 16:28:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

int			ft_vm_instr_add_sub_routine(t_vm *vm,
										t_process *proc,
										unsigned char **ptr,
										int tab[3])
{
	(void)vm;
	(void)proc;
	(void)ptr;
	(void)tab;
	return (EXIT_FAILURE);
	#if 0
	int			i;

	i = 0;
	/* Set up a pointer at the beginning of the arguments */
	*ptr = proc->pc + 2;
	/* Read arguments */
	while (i < proc->op->nb_args)
	{
		tab[i] = **ptr;
		++*ptr;
		++i;
	}
	/* Check if they're all register numbers */
	if (!(IS_REG(tab[0]) && IS_REG(tab[1]) && IS_REG(tab[2])))
	{
		ft_vm_instr_fail(vm, proc,
			2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
			 CARRY_CHANGE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
	#endif
}
