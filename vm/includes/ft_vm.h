/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/11/14 15:32:12 by mvillemi         ###   ########.fr       */
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

# define    OPTION_MAX		6
# define	INSTR_NUMBER	16
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
	#if 0
	unsigned int	idx;
	t_champion[4]	champion;
	#endif
	#if 1
	t_champion		*i_champ;
	t_champion		champion1;
	t_champion		champion2;
	t_champion		champion3;
	t_champion		champion4;
	#endif
}						t_dead_pool;

typedef struct			s_instr_list
{
	void			(*func)(unsigned char arena[], t_dead_pool *dead_pool);
}						t_instr_list;

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
										int *nb_champion);
void		ft_vm_read_dead_pool_magic(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_name(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_size(t_header *champion, const int fd);
void		ft_vm_read_dead_pool_comment(t_header *champion, const int fd);

void		ft_vm_arena(unsigned char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);

void		ft_vm_arena_upload_champion(unsigned char arena[MEM_SIZE],
										int option[OPTION_MAX],
										t_dead_pool *dead_pool,
										int *nb_champion);
void		ft_vm_arena_live_check(t_dead_pool *dead_pool, int *nb_champion);
/*
** Instruction functions
*/
int			ft_vm_instr(unsigned char arena[],
							t_dead_pool *dead_pool,
							int *nb_champion,
							unsigned const int current_cycle);
int			ft_vm_instr_decode(t_dead_pool *dead_pool);
int			ft_vm_instr_jump(t_dead_pool *dead_pool);
void		ft_vm_instr_exec(unsigned char arena[], t_dead_pool *dead_pool);
int			ft_vm_instr_get_data(size_t size, uint8_t *ptr);
int			ft_vm_instr_end_of_game(t_dead_pool *dead_pool, int *nb_champion);
void		ft_vm_instr_champion_routine(unsigned char arena[],
											t_dead_pool * dead_pool,
											unsigned const int current_cycle);
void 		ft_vm_instr_new_process(t_dead_pool *dead_pool);
void		ft_vm_instr_close_provess(t_dead_pool *dead_pool);
void		ft_vm_instr_live(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_ld(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_st(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_add(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_sub(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_and(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_or(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_xor(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_zjmp(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_ldi(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_sti(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_fork(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_lld(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_lldi(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_lfork(unsigned char arena[], t_dead_pool *dead_pool);
void		ft_vm_instr_aff(unsigned char arena[], t_dead_pool *dead_pool);
/*
** Print functions
*/
void		ft_vm_print_arena(void const *data, size_t msize,
								size_t nb_byte, t_dead_pool *dead_pool);
void		ft_vm_print_pc(t_dead_pool *dead_pool);
void 		ft_vm_print_reg(t_champion *champ);
void		ft_vm_print_process(t_dead_pool *dead_pool);


/*
** Tools
*/
extern t_op	g_op_tab[17];
int			ft_atoi(char *str);

#endif
