/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/12 23:21:20 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISASS_H
# define FT_DISASS_H

# include "instruction.h"
# include "timer.h"

# include "ft_list.h"

# ifdef DEBUG
#  define DEBUG_MODE 1
# else
#  define DEBUG_MODE 0
# endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

/*
 * brief       Label structure
 * 
 * param	name		Numero of the label
 * param	byte_pos	Position of the label in the file.cor (whitout header)
 * param	list		list_node
 */
typedef struct		s_label
{
	int				name;
	uint32_t		byte_pos;
	t_list			list;
}					t_label;

/*
 * Label container_of
 */
# define C_LABEL(it)	CONTAINEROF(it, t_label, list)

/*
 * brief	Instruction structure
 * 
 * param	byte_pos	Position of the instruction in the file.cor (without header)
 * param	instr		Instruction (common/instruction.h)
 * param	label_ref	instr->args[i] label reference
 * param	list		list_node
 */
typedef struct		s_instr_node
{
	uint32_t		byte_pos;
	t_instr			*instr;
	t_label			*label_ref[3];
	t_list			list;
}					t_instr_node;

/*
 * Instruction container_of
 */
# define C_INSTR(it)	CONTAINEROF(it, t_instr_node, list)

/*
 * brief 	Disassembler main struct
 * 
 * param	opt			Options
 * param	fd_in		Source file
 * param	fd_out		Destination file
 * param	header		Source file header
 * param	instr_head	Instruction list
 * param	instr_head	Label list
 */
typedef struct		s_disass
{
	t_timer			benchmark[3];
	int				fd_in;
	int				fd_out;
	t_header		header;
	t_list			instr_head;
	t_list			label_head;
}					t_disass;

/*
 * brief	Macro that define the operation to reach the label position
 */
# define DISASS_JUMP(x, y, z)	(int)(((y) + (z)) % (x))

/*
 * brief	Start parsing source file
 */
void				ft_disass(t_disass *dsm);

/*
 * brief	Init disassembler engine
 * 			- Parse option
 * 			- Init source stream
 * 			- Init destination stream
 */
int					ft_disass_init(t_disass *dsm, char const *input_file);

/*
 * brief	Delete disass structure
 */
void				ft_disass_del(t_disass *dsm);

/*
 * brief	Creates label references
 * 
 * 			- First pass, creates label from instruction that specificaly
 * 			  uses label as arguments.
 * 			- Second pass, check if some instruction's argument's data
 * 			  refer to a position where label already exist.
 *      	This has a simplified complexity of O(2n)
 */
void				ft_disass_label(t_disass *dsm);

/*
 * brief	Generate destination file
 */
void				ft_disass_gen(t_disass *dsm);

#endif
