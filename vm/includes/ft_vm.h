/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/21 18:23:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VM_H
# define FT_VM_H

/*
** Personnal Libraries
*/

# include "op.h"
# include "macro.h"
# include "ft_printf.h"
# include "ft_option.h"
# include "ft_ctype.h"
# include "ft_string.h"
# include "get_next_line.h"

/*
** Macros
*/

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
** Defines
*/
# define    OPTION_MAX 6

/*
** Structures
*/

typedef struct      s_vm
{
    char            arena[MEM_SIZE + 1];
}                   t_vm;

#if 0
typedef struct		s_champion
{

}
#endif

/*
** Prototype
*/

int         ft_atoi(char *str);

t_option    *ft_vm_option(int option[OPTION_MAX], int ac, char **av);
void        ft_vm_parse_champion(int option[OPTION_MAX], char **av);
void ft_vm_read_champion(int option[OPTION_MAX], t_header *header);

#endif
