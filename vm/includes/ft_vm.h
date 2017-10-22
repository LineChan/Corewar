/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/22 19:17:02 by mvillemi         ###   ########.fr       */
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
# include "endian.h"

/*
** Standard Libraries
*/

# include <unistd.h>

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
# define    CHAMP_MAX 4

/*
** Structures
*/

typedef struct          s_dead_pool
{
	t_header	champion1;
	t_header	champion2;
	t_header	champion3;
	t_header	champion4;
}						t_dead_pool;

/*
** Singleton
*/

/*
** Prototype
*/

int         ft_atoi(char *str);

t_option    *ft_vm_parse_option(int option[OPTION_MAX], int ac, char **av);
void        ft_vm_parse_champion(int option[OPTION_MAX], char **av);

void        ft_vm_read_champion(int option[OPTION_MAX], t_dead_pool *dead_pool);
void		ft_vm_read_dead_pool_magic(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_name(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_size(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_comment(t_header *champion, const int fd);

#endif
