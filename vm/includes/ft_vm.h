/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/25 00:26:03 by mvillemi         ###   ########.fr       */
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
# define	PC (ft_vm_pc_singleton())

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

typedef struct			s_pc
{
	char		*champion1;
	char		*champion2;
	char		*champion3;
	char		*champion4;
	int			carry1;
	int			carry2;
	int			carry3;
	int			carry4;
	int			register1[REG_NUMBER];
	int			register2[REG_NUMBER];
	int			register3[REG_NUMBER];
	int			register4[REG_NUMBER];
}						t_pc;

/*
** Singleton
*/
t_pc		*ft_vm_pc_singleton(void);

/*
** Prototype
*/

int         ft_atoi(char *str);

t_option    *ft_vm_parse_option(int option[OPTION_MAX], int ac, char **av);
void        ft_vm_parse_champion(int option[OPTION_MAX], char **av);

void        ft_vm_read_champion(int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);
void		ft_vm_read_dead_pool_magic(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_name(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_size(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_comment(t_header *champion, const int fd);

void		ft_vm_arena(char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);
void		ft_vm_arena_print(void const *data, size_t msize, size_t nb_byte);
void		ft_vm_arena_print_pc(void);

void		ft_vm_arena_upload_champion(char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);
void		ft_vm_arena_read_instruction(char *arena);

#endif
