/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/11 21:32:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//#include "ft_instruction_parse.h"
#include "ft_instruction.h"
#include "endian.h"

//TODO : libs
#include "ft_printf.h"
static uint8_t		ft_instruction_parse_data(t_vm *vm,
												t_process *proc,
												uint8_t const i,
												uint8_t const bytecode)
{
	//ft_printf("ft_instruction_parse_data args[%d]\n", i);
	extern t_op		g_op_tab[17];

	/* Parse size */
	#if 0
	ft_printf("\n\nop : %s\n", g_op_tab[proc->next_op].name);
	ft_printf("bytecode : %b\n", bytecode);
	#endif
	proc->instr->args[i].type = (bytecode >> 6) & 0x3;
	/* Get size from arguments' type */
	if (REG_CODE == proc->instr->args[i].type)
	{
		//ft_printf("REG\n");
		proc->instr->args[i].type = T_REG;
		proc->instr->args[i].size = 1;
	}
	else if (DIR_CODE == proc->instr->args[i].type)
	{
		//ft_printf("DIR\n");
		proc->instr->args[i].type = T_DIR;
		proc->instr->args[i].size =  (!proc->instr->op->has_index) ? 4 : 2;
	}
	else if (IND_CODE == proc->instr->args[i].type)
	{
		//ft_printf("IND\n");
		proc->instr->args[i].type = T_IND;
		proc->instr->args[i].size = 2;
	}
	else
	{
		//ft_printf("INVALID ARG\n");
		return (EXIT_FAILURE);
	}
	/* Read data byte by byte */
	proc->instr->args[i].data = ft_instruction_get_data(proc->instr->args[i].size,
													proc->instr->new_pc,
													&vm->arena[0][0],
													IS_BIG_ENDIAN);
	/* Check if the register's number is valid */
	if ((REG_CODE == proc->instr->args[i].type)
		 && !REG_IS_VALID((proc->instr->args[i].data)))
		{
			//ft_printf("{red: parse data args[%d] an invalid register}\n", i);
			return (EXIT_FAILURE);
		}
	/* Check if the type match the instruction */
	#if 0
	ft_printf("g_op_tab[proc->next_op].arg_types[%d] = %b\n", i,g_op_tab[proc->next_op].arg_types[i]);
	ft_printf("proc->instr->args[i].type = %b\n", proc->instr->args[i].type);
	ft_printf(" & --> %b\n", (short)(t_arg_type)g_op_tab[proc->next_op].arg_types[i] & (short)(t_arg_type)proc->instr->args[i].type);
	#endif
	if ((proc->instr->args[i].type & g_op_tab[proc->next_op].arg_types[i]) == 0)
	{
		//ft_printf("The argument type is not compatible\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

uint8_t				ft_instruction_parse(t_vm *vm,
											t_process *proc,
											uint8_t bytecode)
{
	uint8_t		i;
	uint8_t		ret;

	i = 0;
	ret = EXIT_SUCCESS;
	//ft_printf("START PARSING with bytecode %b\n", bytecode);
	while (i < proc->instr->op->nb_args)
	{
		if (ft_instruction_parse_data(vm, proc, i, bytecode) == EXIT_FAILURE)
			ret = EXIT_FAILURE;
		/* Next loop, setup the bytecode, handle the pc jump */
		bytecode <<=2;
		proc->instr->new_pc = vm->arena[0] + LOOP(proc->instr->new_pc +
			proc->instr->args[i].size - vm->arena[0]);
		++i;

	}
	return (ret);
}
#if 0
static int32_t		ft_instruction_parse_data(t_vm *vm,
												t_process *proc,
												int const i,
												uint8_t const bytecode)
{
	/* Parse size */
	proc->instr->args[i].type = (bytecode >> 6) & 0x3;
	/* Get size from arguments' type */
	if (REG_CODE == proc->instr->args[i].type)
		proc->instr->args[i].size = 1;
	else if (DIR_CODE == proc->instr->args[i].type)
		proc->instr->args[i].size =  (!proc->instr->op->has_index) ? 4 : 2;
	else if (IND_CODE == proc->instr->args[i].type)
		proc->instr->args[i].size = 2;
	else
		return (0);
	/* Read data byte by byte */
	proc->instr->args[i].data = ft_instruction_get_data(proc->instr->args[i].size,
													proc->instr->new_pc,
													&vm->arena[0][0],
													IS_BIG_ENDIAN);
	/* Check if the register's number is valid */
	if ((REG_CODE == proc->instr->args[i].type)
		 && !REG_IS_VALID(proc->instr->args[i].data))
		 return (0);
	return (1);
}

void				ft_instruction_parse(t_vm *vm,
											t_process *proc,
											uint8_t bytecode)
{
	int			i;

	i = 0;
	/* Parse each defined argument */
	while (i < proc->instr->op->nb_args)
	{
		if (0 == ft_instruction_parse_data(vm, proc, i, bytecode))
			proc->error = 1;
		/* Next loop, prepare the bytecode, handle the pc jump */
		bytecode <<= 2;
		proc->instr->new_pc =
				vm->arena[0] + LOOP(proc->instr->new_pc +
				proc->instr->args[i].size - vm->arena[0]);
		++i;
	}
	#if 0
	if (proc->error == 1)
		return (0);
	return (1);
	#endif
}
#endif
#if 0
static int32_t	ft_instruction_parse_data(t_instr *this,
										  uint8_t *context,
										  uint8_t bytecode,
										  int i)
{
	/* Parse size */
	this->args[i].type = (bytecode >> 6) & 0x3;

	/* get size from type */
	if (REG_CODE == this->args[i].type)
		this->args[i].size = 1;
	else if (DIR_CODE == this->args[i].type)
		this->args[i].size = (!this->op->has_index) ? 4 : 2;
	else if (IND_CODE == this->args[i].type)
		this->args[i].size = 2;
	else
		return (0);

	/* read data byte by byte */
	this->args[i].data = ft_instruction_get_data(this->args[i].size,
											     this->new_pc,
											     context,
											     IS_BIG_ENDIAN);
	/* Check if register number is valide */
	if (REG_CODE == this->args[i].type && !REG_IS_VALID(this->args[i].data))
		return (0);
	return (1);
}

int32_t		ft_instruction_parse(t_instr *this,
								 uint8_t *context,
								 uint8_t bytecode,
								 int *error)
{
	int		i;

	i = 0;
	/* Parse each arg defined */
	while (i < this->op->nb_args)
	{
		if (0 == ft_instruction_parse_data(this, context, bytecode, i))
		{
			*error = 1;
		}
		/* Next loop, prepare bytecode, handle pc jump */
		bytecode <<= 2;
		this->new_pc = context + LOOP(this->new_pc + this->args[i].size - context);
		++i;
	}
	if (*error == 1)
		return (0);
	return (1);
}
#endif
