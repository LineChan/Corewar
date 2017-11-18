/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/12 17:55:04 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <stdint.h>
# include <stddef.h>
# include "op.h"

/*
 * brief    Instruction's decoded arguments:
 *
 * param type	T_REG | T_DIR | T_IND
 * param data	Data we already applied endianness and type conversion.
 * param size	Size of the current argument (1, 2 or 4 bytes)
 */
typedef struct		s_instr_decode
{
	t_arg_type		type;
	int32_t			data;	
	size_t			size;
}					t_instr_decode;

/*
 * brief    Instruction's encoded arguments:
 *
 * param type	T_REG | T_DIR | T_IND | T_LAB
 * param data	Data we already applied the desired conversion
 * 				T_REG: Target 1 byte:  *(uint8_t *)data;
 * 				T_IND: Target 2 bytes: *(uint16_t *)data;
 * 				T_DIR: Target 4 bytes: *(uint32_t *)data;
 * 				T_LABEL:               data;
 * param size	Size of the current argument (1, 2, 4 bytes, or 0 if T_LAB)
 */
typedef struct		s_instr_encode
{
	t_arg_type		type;
	char			data[1 << 8];
	size_t			size;
}					t_instr_encode;

/*
 * brief    Instruction conversion
 *
 *			The conversion depends on the actual encode/decode
 *			engine used.
 *			ft_instruction_decode:
 *				-> Conversion from BIG_ENDIAN to LITTLE_ENDIAN
 *			ft_instruction_encode:
 *				-> Conversion from LITTLE_ENDIAN to BIG_ENDIAN
 */
typedef union		u_instr_conv
{
	t_instr_decode	*decode;
	t_instr_encode	*encode;
}					t_instr_conv;

/*
 * brief    Instruction struct is a copy of g_op_tab[n] with decoded data of
 * 			the target instruction
 *
 * +param	op			Instruction &g_op_tab[x];
 * +param	args		Instruction's argument array, allocated with op->nb_args
 * +param	instr_size	Total size of the instruction
 */
typedef struct		s_instr
{
	int				type;
	uint8_t			bytecode;
	t_op			*op;
	t_instr_conv	args;
	size_t			instr_size;
}					t_instr;

/*
 * brief	Instruction type that define the conversion used.
 */
# define INSTR_ENCODE	0x00
# define INSTR_DECODE 	0x01

/*
 * @brief 	Decode instruction from PC
 * 
 * 			That function assume PC is a pointer to a
 * 			valide instruction code.
 * 			
 * 			Examples:
 * 			
 * 			[PC]	(pc point to instruction live)
 * 			 |
 * 			 v
 * 			0x01 0x00 0x00 0x00 0x2a
 * 			 ^   [-----------------]
 * 			 |            ^
 * 			 |            |
 * 		   live    T_DIR (4 bytes)
 * 			
 * 			0x02 0x90 0x00 0x00 0x00 0x00 0x05
 * 			 ^    ^   [-----------------]  ^
 * 			 |    |            |           |
 * 		     ld  byte   T_DIR (4 bytes)  T_REG (1 byte)
 * 			     code
 * 			     			   
 * 		   bytecode: 0x90 = 0b10010000
 * 		   					  |/|/
 * 		   					  | |__ Second 2 bits defines T_REG
 * 		   					  |
 * 		   					  |____ First 2 bits defines T_DIR
 * 		   					  
 * 		   bytecode as only 2 pairs of 2 bits used, so the
 * 		   instruction 'ld' has only two parameters.
 */
t_instr		*ft_instruction_decode(void const *pc);

/*
 * @brief 	Encode instruction from a VALIDE line (ex: "live %10")
 * 
 *         	That function does not check any of lexical,
 *         	syntaxical or semantical redcode rules. It does
 *         	only apply a `match' indexing.
 */
t_instr		*ft_instruction_encode(int argc, char **argv);

/*
 * @brief	Delete instruction details
 */
void		ft_instruction_del(t_instr **ptr);

#endif
