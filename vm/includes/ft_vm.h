/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/11/02 08:27:29 by mvillemi         ###   ########.fr       */
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

#ifdef DEBUG
# define DEBUG_MODE 1
#else
# define DEBUG_MODE 0
#endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

/*
** Defines
*/

# define    OPTION_MAX		6

#if 1
# define LIVE		1
# define LD			2
# define ST			3
# define ADD		4
# define SUB		5
# define AND		6
# define OR			7
# define XOR		8
# define ZJUMP		9
# define LDI		10
# define STI		11
# define FORK		12
# define LLD		13
# define LLDI		1ampjkk
# define LFORK		15
# define AFF		16
#endif

typedef struct			s_vm_instr
{
	unsigned int		bytecode;
	unsigned char		index;
	t_op				*op;
	//size_t				jump;
	int					arg_jump[MAX_ARGS_NUMBER];
	t_list				list;

}						t_vm_instr;

typedef struct			s_champion
{
	unsigned int		live;
	unsigned int		carry;
	int					reg[REG_NUMBER];
	unsigned char		*pc;
	unsigned int		next_cycle;
	t_header			header;
	t_vm_instr			instr;
	//t_arg_type			arg_jump[MAX_ARGS_NUMBER];
}						t_champion;


#if 0
typedef struct		s_instr
{
	int				type;
	uint8_t			bytecode;
	t_op			*op;
	t_instr_conv	args;
	size_t			instr_size;
}					t_instr;
#endif

/*
** Structures
*/

typedef struct          s_dead_pool
{
	t_champion		champion1;
	t_champion		champion2;
	t_champion		champion3;
	t_champion		champion4;
}						t_dead_pool;

typedef struct			s_instr_list
{
	void			(*func)(unsigned char arena[], t_champion *champ);
}						t_instr_list;


/*
** Singleton
*/
t_champion		*ft_champion1(void);
t_champion		*ft_champion2(void);
t_champion		*ft_champion3(void);
t_champion		*ft_champion4(void);

/*
** Prototype
*/

extern t_op	g_op_tab[17];

int				ft_atoi(char *str);

t_option		*ft_vm_parse_option(int option[OPTION_MAX], int ac, char **av);

/*
** Parse functions
*/
void			ft_vm_parse_champion(int option[OPTION_MAX], char **av);
void			ft_vm_read_champion(int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);
void			ft_vm_read_dead_pool_magic(t_header *champion, const int fd);
void			ft_vm_read_dead_pool_name(t_header *champion, const int fd);
void			ft_vm_read_dead_pool_size(t_header *champion, const int fd);
void			ft_vm_read_dead_pool_comment(t_header *champion, const int fd);

void			ft_vm_arena(unsigned char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);

void			ft_vm_arena_upload_champion(unsigned char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);

/*
** Instruction functions
*/
void			ft_vm_instr(unsigned char arena[],
										t_dead_pool *dead_pool,
										int *nb_champion);
int				ft_vm_instr_read(unsigned char arena[], t_dead_pool *dead_pool, const int nb_champion);
void			ft_vm_instr_decode(t_champion *champ);
void 			ft_vm_instr_bytecode(t_champion *champ);
void			ft_vm_instr_jump(t_champion *champ);
void			ft_vm_instr_exec(unsigned char arena[], t_champion *champ);
void			ft_vm_instr_sti(unsigned char arena[], t_champion *champ);

/*
** Print functions
*/
void			ft_vm_print_arena(void const *data, size_t msize,
										size_t nb_byte);
void			ft_vm_print_pc(t_dead_pool *dead_pool);

#endif
