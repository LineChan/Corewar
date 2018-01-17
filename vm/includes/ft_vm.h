/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:24:09 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/17 17:56:50 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Generate zaz output:
for i in {1..150}; do ./docs/ressources/corewar ./champions/lld.cor -v 20 -d $i > zaz_dump/ldi_${i}; done
*/

#ifndef FT_VM_H
# define FT_VM_H

/*
** Personnal Libraries
*/

# include "op.h"
# include "ft_list.h"
# include "macro.h"

/*
** Standard Libraries
*/
#include <stdlib.h>

/*
** Defines
*/

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

# define CARRY_CHANGE    1
# define INSTR_NUMBER    17

#if 1
# define MOD(x)	        (((x) < 0) ? (MEM_SIZE + ((x) % MEM_SIZE)) : ((x) % MEM_SIZE))
# define IDX(x)	        (((x) < 0) ? (IDX_MOD + ((x) % IDX_MOD)) : ((x) % IDX_MOD))
#endif
# define ASSERT(x)      ft_assert(# x, __FUNCTION__, __LINE__, x)

# define VM_DIR_SIZE(x)	((x) ? 2 : 4)

#if 0
# define LOG_OPT        (vm->option.log)
# define DISP_OPT		(vm->option.display)
# define DUMP_OPT		(vm->option.dump)
# define S_DUMP_OPT		(vm->option.s)
#endif


# define C_PROCESS(it)	CONTAINEROF(it, t_proc, list)

/*
** Define flags
*/

# define FLAG_1			(1 << 0)
# define FLAG_2			(1 << 1)
# define FLAG_4			(1 << 2)
# define FLAG_8			(1 << 3)
# define FLAG_16		(1 << 4)
# define FLAG_32		(1 << 5)

/*
** Comparisons
*/

#if 0
# define DISPLAY_1		(vm->option.display & FLAG_1)
# define DISPLAY_2		(vm->option.display & FLAG_2)
# define DISPLAY_4		(vm->option.display & FLAG_4)
# define DISPLAY_8		(vm->option.display & FLAG_8)
# define DISPLAY_16		(vm->option.display & FLAG_16)
# define DISPLAY_32		(vm->option.display & FLAG_32)
#endif

/*
** Structures
*/
struct s_instr;

/*
** State machine
*/
typedef struct		s_opt_map
{
	char			*opt;
	size_t			len;
	int				state;
}					t_option_map;

typedef enum		e_opt_parse_state
{
	OPT_STATE_DEFAULT = 0,
	OPT_STATE_N,
	OPT_STATE_S,
	OPT_STATE_CTMO,
	OPT_STATE_DUMP,
	OPT_STATE_NUMBER,
	OPT_STATE_DISPLAY,
	OPT_STATE_STEALTH,
	OPT_STATE_PROC,
	OPT_STATE_START_CYCLE,
	OPT_STATE_ROUND_LIMIT,
	OPT_STATE_PROCESS_LIMIT,
	OPT_STATE_LOG,
	OPT_ERROR
}					t_option_parse_state;

typedef struct		s_parse
{
	int				state;
	int				*next_arg;
	int				ac;
	int				fd[MAX_PLAYERS];
	char			**av;
}					t_parse;

typedef struct		s_opt
{
	int				display;
	int				dump;
	int				state;
}					t_opt;

typedef struct		s_proc
{
	int				dead;
	int				parent_nb;
	int				proc_nb;
	int				error;
	int				live;
	int				has_lived;
	int				carry;
	int				exec_cycle;
	int				reg[REG_NUMBER + 1];
	int				pc;
	unsigned char	next_op;
	t_op			*op;
	t_list			list;
}					t_proc;

typedef struct		s_vm
{
	int				fd[MAX_PLAYERS];
	int				nb_proc;
	int				current_cycle;
	int				current_proc_nb;
	int				cycle_to_die;
	int				last_alive;
	int				total_live;
	unsigned char	arena[2][MEM_SIZE];
	t_opt			opt;
	t_header		header[MAX_PLAYERS];
	t_list			proc_head;
}					t_vm;

//typedef void            (*t_func)(t_vm *, t_process *);

typedef void			(*t_state_machine)(t_vm *vm, t_parse *parse);
/*
** Prototypes
*/

/*
** Tool and Print functions
*/
void		ft_exit(char const *str);
int			ft_atoi(char *str);
void		ft_assert(char const *condition,
						char const *function_name,
						int const line_number,
						const int code_condition);
void		ft_print_intro(t_vm const *vm);

/*
** Parse functions
*/

void		ft_parse(t_vm *vm, int const ac, char **av);
void		ft_parse_nb(t_vm *vm, t_parse *parse);
void		ft_parse_default(t_vm *vm, t_parse *parse);
void		ft_parse_proc(t_vm *vm, t_parse *parse);
void		ft_parse_n(t_vm *vm, t_parse *parse);
void		ft_parse_dump(t_vm *vm, t_parse *parse);
void		ft_parse_display(t_vm *vm, t_parse *parse);
void		ft_parse_proc_repartition(t_vm *vm, t_parse *parse);

/*
** Header functions
*/

void		ft_header(t_vm *vm);
void		ft_header_magic(t_vm *vm, int const i);
void		ft_header_name(t_vm *vm, int const i);
void		ft_header_size(t_vm *vm, int const i);
void		ft_header_comment(t_vm *vm, int const i);

/* Arena functions */

void		ft_arena(t_vm *vm);
void		ft_arena_upload(t_vm *vm);
void		ft_arena_cycle_routine(t_vm *vm);

/*
** Processses functions
*/

void		ft_new_proc(t_vm *vm, int const i, int const index);

/*
** Instruction functions
*/

void		ft_instr_update_exec_cycle(t_vm *vm, t_proc *proc);

#endif
