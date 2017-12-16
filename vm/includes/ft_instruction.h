/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2017/12/15 16:22:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRUCTION_H
# define FT_INSTRUCTION_H

# include <stdint.h>
# include <stddef.h>
# include "op.h"

# define LOOP(x)				(((x) % MEM_SIZE) + (((x) < 0) ? MEM_SIZE : 0))

# define OPCODE_IS_VALID(x)		(16 > (uint32_t)((x) - 1))
# define REG_IS_VALID(x)		(REG_NUMBER > (uint32_t)((x) - 1))

typedef struct		s_instr_decode
{
	t_arg_type		type;
	int32_t			data;
	size_t			size;
}					t_instr_decode;

typedef struct		s_instr
{
	t_op			*op;
	uint8_t			*new_pc;
	t_instr_decode	args[4];
}					t_instr;

t_instr				*ft_instruction_decode(uint8_t *pc,
										   uint8_t *context,
										   int *error);

void				ft_instruction_del(t_instr **ptr);


int32_t				ft_instruction_get_data(size_t bytes,
											uint8_t *pc,
											uint8_t *context,
											int	endian_mode);

void				ft_instruction_set_data(size_t bytes,
											uint8_t *pc,
											uint8_t *context,
											uint8_t *arena);

#endif
