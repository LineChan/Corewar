/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/31 13:48:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRUCTION_H
# define FT_INSTRUCTION_H

# include <stdint.h>
# include <stddef.h>
# include "op.h"


# define OPCODE_IS_VALID(x)		(16 > (uint32_t)((x) - 1))
# define REG_IS_VALID(x)		(REG_NUMBER > (uint32_t)((x) - 1))

# define OPCODE_NOT_VALID		2

struct s_vm;
struct s_proc;

typedef struct		s_instr_decode
{
	t_arg_type		type;
	int32_t			data;
	size_t			size;
}					t_instr_decode;

typedef struct		s_instr
{
	t_op			*op;
	int				new_pc;
	int				size;
	int				zjmp_success;
	t_instr_decode	args[4];
}					t_instr;

/*
** Prototypes
*/

uint8_t		ft_instr_parse(struct s_vm *vm, struct s_proc *proc, int bytecode);
uint8_t		ft_instr_parse_data(struct s_vm *vm,
								struct s_proc *proc,
								uint8_t const i,
								uint8_t const bytecode);
uint8_t		ft_instr_setup(struct s_vm *vm, struct s_proc *proc);
uint8_t		ft_instr_decode(struct s_vm *vm, struct s_proc *proc);

#endif
