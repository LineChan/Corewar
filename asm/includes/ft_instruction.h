/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 16:46:30 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRUCTION_H
# define FT_INSTRUCTION_H

# include <stdint.h>
# include <stddef.h>
# include "op.h"

typedef struct		s_instr_encode
{
	t_arg_type		type;
	char			data[1024];
	size_t			size;
}					t_instr_encode;

typedef struct		s_instr
{
	t_op			*op;
	int8_t			bytecode;
	t_instr_encode	args[4];
	size_t			instr_size;
}					t_instr;

t_instr				*ft_instruction_encode(int tab_size, char **tab);

void				ft_instruction_del(t_instr **ptr);

int32_t				ft_instruction_encode_get_number(char const *data);

int8_t				ft_instruction_encode_set_args(t_instr *st, int tab_size, char **tab);

int8_t				ft_instruction_encode_reg(t_instr *st, int arg_index, char const *data);

int8_t				ft_instruction_encode_dir(t_instr *st, int arg_index, char const *data);

int8_t				ft_instruction_encode_ind(t_instr *st, int arg_index, char const *data);


#endif
