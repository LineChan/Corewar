/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 17:38:47 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISASS_H
# define FT_DISASS_H

# include "instruction.h"
# include "ft_option.h"
# include "ft_string.h"
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
 * brief       Label structure, defined by a name and a position.
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
 * brief	Instruction structure, with a byte position and a lebel reference
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
	t_option		*opt;
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
 * brief	Delete disass structure
 */
void				ft_disass_del(t_disass *dsm);

/*
 * brief	Creates label references
 * 
 * 			Complexity O(2 * nb_instr)
 */
void				ft_label_set(t_disass *dsm);

/*
 * brief	Generate destination file
 */
void				ft_gen(t_disass *dsm);

#endif
