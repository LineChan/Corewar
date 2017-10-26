/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/26 16:33:37 by mvillemi         ###   ########.fr       */
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

# define    OPTION_MAX		6
# define    CHAMP_MAX		4

# define	CHAMP_1			(ft_champion1())
# define	PC_1			(CHAMP_1->pc)
# define	CARRY_1			(CHAMP_1->carry)
# define	REG_1			(CHAMP_1->reg)
# define	LIVE_1			(CHAMP_1->live)
# define	CYCLE_1			(CHAMP_1->cycle)

# define	CHAMP_2			(ft_champion2())
# define	PC_2			(CHAMP_2->pc)
# define	CARRY_2			(CARRY_2->carry)
# define	REG_2			(CHAMP_2->reg)
# define	LIVE_2			(CHAMP_2->live)
# define	CYCLE_2			(CHAMP_2->cycle)

# define	CHAMP_3			(ft_champion3())
# define	PC_3			(CHAMP_3->pc)
# define	CARRY_3			(CHAMP_3->carry)
# define	REG_3			(CHAMP_3->reg)
# define	LIVE_3			(CHAMP_3->live)
# define	CYCLE_3			(CHAMP_3->cycle)

# define	CHAMP_4			(ft_champion4())
# define	PC_4			(CHAMP_4->pc)
# define	CARRY_4			(CHAMP_4->carry)
# define	REG_4			(CHAMP_4->reg)
# define	LIVE_4			(CHAMP_4->live)
# define	CYCLE_4			(CHAMP_4->cycle)


# define C_CHAMP(it)		CONTAINEROF(it, t_champion, champion_head)
# define C_INSTR(it)		CONTAINEROF(it, t_vm_instr, list)
# define INSTR_BCODE(it)	(C_INSTR(it)->bytecode)
# define INSTR_OP(it)		(C_INSTR(it)->op)
# define INSTR_JUMP(it)		(C_INSTR(it)->jump)

typedef struct			s_champion
{
	unsigned int		live;
	unsigned int		carry;
	int					reg[REG_NUMBER];
	unsigned char		*pc;
	unsigned int		next_cycle;
	t_list				champion_head;
}						t_champion;

typedef struct			s_vm_instr
{
	uint8_t				bytecode;
	int					index;
	t_op				*op;
	size_t				jump;
	t_list				list;

}						t_vm_instr;

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
	t_header	champion1;
	t_header	champion2;
	t_header	champion3;
	t_header	champion4;
}						t_dead_pool;




/*
** Singleton
*/
t_champion		*ft_champion1(void);
t_champion		*ft_champion2(void);
t_champion		*ft_champion3(void);
t_champion		*ft_champion4(void);
void			ft_del_singl_champ(t_list *champ);

/*
** Prototype
*/

extern t_op	g_op_tab[17];

int				ft_atoi(char *str);

t_option		*ft_vm_parse_option(int option[OPTION_MAX], int ac, char **av);
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
void			ft_vm_arena_print(void const *data, size_t msize,
										size_t nb_byte);
void			ft_vm_arena_print_pc(void);

void			ft_vm_arena_upload_champion(unsigned char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);
void			ft_vm_arena_read_instr(unsigned char arena[],
										t_dead_pool *dead_pool);
void			ft_vm_instr_decode(unsigned char arena[], t_champion *champ);
void			ft_vm_instr_add(unsigned char arena[], t_champion *champion);
void 			ft_vm_instr_del(t_list *src);
void			ft_vm_instruct_live(unsigned char arena[]);

#endif
