/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:24:09 by mvillemi          #+#    #+#             */
/*   Updated: 2018/02/01 23:15:08 by mvillemi         ###   ########.fr       */
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
#include "ft_visual.h"
# include "macro.h"

/*
** Standard Libraries
*/
# include <stdlib.h>
# include <stdint.h>

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

# define LOOP(x)				(((x) % MEM_SIZE) + (((x) < 0) ? MEM_SIZE : 0))
# define ASSERT(x)      ft_assert(# x, __FUNCTION__, __LINE__, x)


# define DISP_OPT			(vm->opt.display)
# define DUMP_OPT			(vm->opt.dump)
# define S_DUMP_OPT			(vm->opt.s)
# define ROUND_LIMIT_OPT	(vm->opt.round_limit)
# define STEALTH_OPT		(vm->opt.stealth)
# define PROC_LIMIT_OPT		(vm->opt.proc_limit)


# define C_PROCESS(it)	CONTAINEROF(it, t_proc, list)

/*
** Comparisons
*/

# define DISPLAY_1		(vm->opt.display & (1 << 0))
# define DISPLAY_2		(vm->opt.display & (1 << 1))
# define DISPLAY_4		(vm->opt.display & (1 << 2))
# define DISPLAY_8		(vm->opt.display & (1 << 3))
# define DISPLAY_16		(vm->opt.display & (1 << 4))
# define DISPLAY_32		(vm->opt.display & (1 << 5))


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
	OPT_STATE_HELP,
	OPT_STATE_N,
	OPT_STATE_S,
	OPT_STATE_AFF,
	OPT_STATE_DUMP,
	OPT_STATE_NUMBER,
	OPT_STATE_DISPLAY,
	OPT_STATE_STEALTH,
	OPT_STATE_PROC,
	OPT_STATE_START_CYCLE,
	OPT_STATE_ROUND_LIMIT,
	OPT_STATE_PROCESS_LIMIT,
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
	int				display_aff;
	int				dump;
	int				s;
	int				stealth;
	int				state;
	int				proc_limit;
	int				round_limit;
	int				death[MAX_PLAYERS];
}					t_opt;

typedef struct		s_proc
{
	int				has_lived;
	int				live_per_round;
	int				parent_nb;
	int				proc_nb;
	int				carry;
	int				exec_cycle;
	int				reg[REG_NUMBER + 1];
	int				pc;
	unsigned char	next_op;
	struct s_instr	*instr;
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
	int				check;
	unsigned char	arena[MEM_SIZE];
	t_opt			opt;
	t_header		header[MAX_PLAYERS];
	t_visual		visual;
	t_list			proc_head;
}					t_vm;

/* Typedef */

typedef void            (*t_func)(t_vm *, t_proc *);
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
void		ft_print_intro(t_vm *vm);

/*
** Parse functions
*/

void		ft_parse(t_vm *vm, int const ac, char **av);
void		ft_parse_nb(t_vm *vm, t_parse *parse);
void		ft_parse_aff(t_vm *vm, t_parse *parse);
void		ft_parse_default(t_vm *vm, t_parse *parse);
void		ft_parse_proc(t_vm *vm, t_parse *parse);
void		ft_parse_n(t_vm *vm, t_parse *parse);
void		ft_parse_s(t_vm *vm, t_parse *parse);
void		ft_parse_dump(t_vm *vm, t_parse *parse);
void		ft_parse_display(t_vm *vm, t_parse *parse);
void		ft_parse_proc_repartition(t_vm *vm, t_parse *parse);
void		ft_parse_help(t_vm *vm, t_parse *parse);
void		ft_parse_start_cycle(t_vm *vm, t_parse *parse);
void		ft_parse_stealth(t_vm *vm, t_parse *parse);
void		ft_parse_round_limit(t_vm *vm, t_parse *parse);
void		ft_parse_proc_limit(t_vm *vm, t_parse *parse);

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
void		ft_arena_setup(t_vm *vm, int *limit, int *round_limit);
void		ft_arena_upload(t_vm *vm);
int			ft_arena_cycle_routine(t_vm *vm);
void		ft_arena_instr_routine(t_list *it, void *context);
void		ft_arena_round_check(t_vm *vm);

int8_t		ft_arena_get_int8(t_vm *arena, int pc);
int16_t		ft_arena_get_int16(t_vm *vm, int pc);
int32_t		ft_arena_get_int32(t_vm *vm, int pc);
void		ft_arena_set_int8(t_vm *vm,
								int const pc,
								int const val,
								int const nb);
void		ft_arena_set_int32(t_vm *vm,
								int const pc,
								int const val,
								int const nb);

/*
** Processses functions
*/

void		ft_new_proc(t_vm *vm, int const i, int const index);
void		ft_del_proc_list(t_vm *vm);
void		ft_del_proc(t_list *node);
void		ft_new_proc_kid(t_vm *vm, t_proc *pro, unsigned int const index);
void		ft_proc_check(t_list *it, void *context);
t_list		*ft_find_proc(t_list *head, int nb);

/*
** Instruction functions
*/

void		ft_instr_update_exec_cycle(t_proc *proc);
void		ft_instr_and_or_xor_routine(t_vm *vm, t_proc *proc);
void		ft_instr_live(t_vm *vm, t_proc *proc);
void		ft_instr_ld(t_vm *vm, t_proc *proc);
void		ft_instr_st(t_vm *vm, t_proc *proc);
void		ft_instr_add(t_vm *vm, t_proc *proc);
void		ft_instr_sub(t_vm *vm, t_proc *proc);
void		ft_instr_and(t_vm *vm, t_proc *proc);
void		ft_instr_or(t_vm *vm, t_proc *proc);
void		ft_instr_xor(t_vm *vm, t_proc *proc);
void		ft_instr_zjmp(t_vm *vm, t_proc *proc);
void		ft_instr_ldi(t_vm *vm, t_proc *proc);
void		ft_instr_sti(t_vm *vm, t_proc *proc);
void		ft_instr_fork(t_vm *vm, t_proc *proc);
void		ft_instr_lld(t_vm *vm, t_proc *proc);
void		ft_instr_lldi(t_vm *vm, t_proc *proc);
void		ft_instr_lfork(t_vm *vm, t_proc *proc);
void		ft_instr_aff(t_vm *vm, t_proc *proc);

/*
** Display functions
*/

int			ft_display_arena(t_vm *vm);
void		ft_display_winner(t_vm *vm);
void		ft_display_pc(t_vm *vm, t_proc const *proc);
void		ft_display_live(t_vm *vm, t_proc const *proc, t_list const *it);
void		ft_display_ld_lld(t_proc const *proc);
void		ft_display_add_sub(t_proc const *proc);
void		ft_display_ldi(t_proc const *proc);
void		ft_display_sti(t_proc const *proc);
void		ft_display_lldi(t_proc const *proc);

#endif
