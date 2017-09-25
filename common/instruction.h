/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/25 08:20:41 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <stdint.h>
# include <stddef.h>
# include "op.h"

typedef struct		s_instr_args
{
	t_arg_type		type;
	char			data[4];
}					t_instr_args;

typedef struct		s_instr
{
	char			*name;
	char			*desc;
	size_t			nb_args;
	t_instr_args	*args;
	size_t			instr_size;
}					t_instr;

/*
 * @brief 	Get instruction details from pc
 */
t_instr		*ft_instruction_get(void *pc);

/*
 * @brief	Delete instruction details
 */
void		ft_instruction_del(t_instr **ptr);

#endif
