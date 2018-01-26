/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:11:11 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/26 00:22:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

uint8_t		ft_instr_parse(t_vm *vm, t_proc *proc, int bytecode)
{
	uint8_t			i;
	uint8_t			ret;

	i = 0;
	ret = EXIT_SUCCESS;
	while (i < proc->instr->op->nb_args)
	{
		/* Get the type and the size of the argument */
		if (ft_instr_parse_data(vm, proc, i, bytecode) == EXIT_FAILURE)
			ret = EXIT_FAILURE;
		/* Next loop, setup the bytecode, handle the pc jump */
		bytecode <<= 2;
		++i;
	}
	return (ret);
}
