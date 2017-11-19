/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/11/19 18:36:08 by mvillemi         ###   ########.fr       */
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
** Modes
*/

#ifdef DEBUG
# define DEBUG_MODE 1
#else
# define DEBUG_MODE 0
#endif

#ifdef TESTS
# define TEST_MODE 1
#else
# define TEST_MODE 0
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

# define	C_PROCESS(it)	CONTAINEROF(it, t_process, list)

# define	CARRY_CHANGE	1
# define    OPTION_MAX		6
# define	INSTR_NUMBER	16
# define	CHAMP_IDX		(dead_pool->idx % MAX_PLAYERS)
# define	OPTION_LOG	option[5]
# define	OPTION_WAIT		option[0]

# define	MOD(x)			((x) < 0) ? (MEM_SIZE + ((x) % MEM_SIZE)) : ((x) % MEM_SIZE)
# define	IS_REG(x)		(!IS_NEG(x) && (x < REG_NUMBER))
/*
** Structures
*/

typedef struct			s_vm_instr
{
	unsigned int		bytecode;
	t_op				*op;
	int					arg_jump[MAX_ARGS_NUMBER];

}						t_vm_instr;

typedef struct			s_champion
{
	unsigned int		live;
	unsigned int		carry;
	unsigned int		reg[REG_NUMBER];
	unsigned int		next_cycle;
	unsigned int		index;
	unsigned int		done;
	unsigned char		*pc;
	t_header			header;
	t_vm_instr			instr;
	t_list				process_head;
}						t_champion;

typedef struct          s_dead_pool
{
	unsigned int	idx;
	unsigned int	current_cycle;
	t_champion		champ[4];
	t_champion		*i_champ;
}						t_dead_pool;

typedef struct			s_instr_list
{
	void			(*func)(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
}						t_instr_list;

#if 0
typedef struct			s_instr_log
{
	void 			(*func)(t_dead_pool *dead_pool, va_list ap);
}						t_instr_log;
#endif
/*
** Linked Lists
*/

typedef struct		s_process
{
	t_champion	process;
	t_list		list;
}				t_process;

/*
** Prototypes
*/

/*
** Commun function
*/
int			ft_instruction_get_data(size_t size, uint8_t *pc);

/*
** Parse functions
*/
t_option	*ft_vm_parse_option(int option[OPTION_MAX], int ac, char **av);
void		ft_vm_parse_champion(int option[OPTION_MAX], char **av);
void		ft_vm_read_champion(int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										unsigned int *nb_champion);
void		ft_vm_read_dead_pool_magic(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_name(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_size(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_comment(t_header *champion, const int fd);

void		ft_vm_arena(unsigned char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										unsigned int *nb_champion);

void		ft_vm_arena_upload_champion(unsigned char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										unsigned int *nb_champion);
void		ft_vm_arena_live_check(t_dead_pool *dead_pool, unsigned int *nb_champion);
/*
** Instruction functions
*/
void		ft_vm_instr(unsigned char arena[],
							int option[OPTION_MAX],
							t_dead_pool *dead_pool,
							unsigned int *nb_champion);
void		ft_vm_instr_fail(t_dead_pool *dead_pool, int carry_change);
int			ft_vm_instr_decode(t_dead_pool *dead_pool);
int			ft_vm_instr_jump(t_dead_pool *dead_pool);
void		ft_vm_instr_exec_routine(unsigned char arena[],
										t_dead_pool *dead_pool,
										int option[OPTION_MAX]);
void		ft_vm_instr_exec(unsigned char arena[],
							t_dead_pool *dead_pool,
							int option[OPTION_MAX]);
int			ft_vm_instr_get_data(size_t size, uint8_t *ptr);
int			ft_vm_instr_end_of_game(t_dead_pool *dead_pool, unsigned int *nb_champion);
void		ft_vm_instr_champion_routine(unsigned char arena[],
											t_dead_pool * dead_pool,
											int option[OPTION_MAX]);
int 		ft_vm_instr_check_if_done(t_dead_pool *dead_pool);
void 		ft_vm_instr_new_process(t_dead_pool *dead_pool);
void		ft_vm_instr_close_process(t_dead_pool *dead_pool);
void		ft_vm_instr_live(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_ld(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_st(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_add(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_sub(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_and(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_or(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_xor(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_zjmp(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_ldi(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_sti(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_fork(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_lld(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_lldi(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_lfork(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);
void		ft_vm_instr_aff(unsigned char arena[], t_dead_pool *dead_pool, int option[OPTION_MAX]);

/*
** Print functions
*/
void		ft_vm_print_arena(void const *data, size_t msize,
								size_t nb_byte, t_dead_pool *dead_pool);
void		ft_vm_print_pc(t_dead_pool *dead_pool);
void 		ft_vm_print_reg(t_champion *champ);
void		ft_vm_print_process(t_dead_pool *dead_pool);
void		ft_vm_print_stat(t_dead_pool *dead_pool, int option[OPTION_MAX]);

/*
** Logger functions
*/
void				ft_vm_log_start(t_dead_pool *dead_pool, int option[OPTION_MAX]);
void 				ft_vm_log_arg(t_dead_pool *dead_pool);
//void				ft_vm_log_instr(t_dead_pool *dead_pool, ...);
void 				ft_vm_log_live(t_dead_pool *dead_pool, int nb);
void 				ft_vm_log_ld(t_dead_pool *dead_pool,
								unsigned char *ptr,
								unsigned int address);
void 				ft_vm_log_st(t_dead_pool *dead_pool,
									unsigned char arena[],
									int dir);
void 				ft_vm_log_add(t_dead_pool *dead_pool, unsigned int add[]);
void 				ft_vm_log_sub(t_dead_pool *dead_pool, unsigned int sub[]);
void				ft_vm_log_and(t_dead_pool *dead_pool,
									unsigned char *ptr,
									unsigned int and[2]);
void				ft_vm_log_or(t_dead_pool *dead_pool,
									unsigned char *ptr,
									unsigned int or[2]);
void 				ft_vm_log_xor(t_dead_pool *dead_pool,
									unsigned char *ptr,
									unsigned int xor[2]);
void				ft_vm_log_zjump(t_dead_pool *dead_pool, int jump);
void				ft_vm_log_ldi(t_dead_pool *dead_pool, unsigned char *ptr);
void				ft_vm_log_sti(t_dead_pool *dead_pool,
									unsigned char arena[MEM_SIZE],
									unsigned int reg,
									unsigned int address);
void				ft_vm_log_fork(t_dead_pool *dead_pool, unsigned int jump);
/*
** Tools
*/
extern t_op	g_op_tab[17];
int			ft_atoi(char *str);

#endif
