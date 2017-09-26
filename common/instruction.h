/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/27 01:42:49 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <stdint.h>
# include <stddef.h>
# include "op.h"

/*
 * brief    Instruction's arguments:
 *
 * param type	T_REG | T_DIR | T_IND
 * param size	Size of the current argument (1, 2 or 4 bytes)
 * param data	Data we already applied endianness and type conversion.
 */
typedef struct		s_instr_args
{
	t_arg_type		type;
	size_t			size;
	int				data;
}					t_instr_args;

/*
 * brief    Instruction struct
 *
 * +param	op			Instruction byte code (g_op_tab->numero)
 * +param	args		Instruction's argument array, determined by nb_args
 * +param	instr_size	Total size of the instruction
 */
typedef struct		s_instr
{
	int				op;
	char			*name;
	char			*desc;
	int				nb_cycles;
	int				has_index;
	size_t			nb_args;
	t_instr_args	*args;
	size_t			instr_size;
}					t_instr;

/*
 * @brief 	Get instruction details from pc
 */
t_instr		*ft_instruction_get(void const *pc);

/*
 * @brief	Delete instruction details
 */
void		ft_instruction_del(t_instr **ptr);

#endif
