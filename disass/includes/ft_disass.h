/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/27 08:38:18 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISASS_H
# define FT_DISASS_H

# include "ft_option.h"
# include "ft_list.h"
# include "instruction.h"

typedef struct		s_instr_list
{
	t_instr			*instr;
	t_list			list;
}					t_instr_list;

# define C_INSTR(it)	CONTAINEROF(it, t_instr_list, list)->instr

typedef struct		s_disass
{
	t_option		*opt;
	t_header		header;
	t_list			instr_head;
}					t_disass;

void				ft_disass(t_disass *dsm, int const fd);

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

#endif
