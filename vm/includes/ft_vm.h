/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:24:09 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/11 17:39:10 by mvillemi         ###   ########.fr       */
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
#include "macro.h"

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

# define MOD(x)	        (((x) < 0) ? (MEM_SIZE + ((x) % MEM_SIZE)) : ((x) % MEM_SIZE))
# define IDX(x)	        (((x) < 0) ? (IDX_MOD + ((x) % IDX_MOD)) : ((x) % IDX_MOD))
# define ASSERT(x)      ft_assert(# x, __FUNCTION__, __LINE__, x)

# define IS_INSTR(x)    ((unsigned int)((x) - 1) < INSTR_NUMBER)
# define IS_REG(x)      ((unsigned int)((x) - 1) < REG_NUMBER)

# define LOG_OPT        (vm->option.log)
# define DISP_OPT		(vm->option.display)
# define DUMP_OPT		(vm->option.dump)
# define S_DUMP_OPT		(vm->option.s)


# define C_PROCESS(it)	CONTAINEROF(it, t_process, list)

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

# define DISPLAY_1		(vm->option.display & FLAG_1)
# define DISPLAY_2		(vm->option.display & FLAG_2)
# define DISPLAY_4		(vm->option.display & FLAG_4)
# define DISPLAY_8		(vm->option.display & FLAG_8)
# define DISPLAY_16		(vm->option.display & FLAG_16)
# define DISPLAY_32		(vm->option.display & FLAG_32)

/*
** Structures
*/

typedef struct		s_option_map
{
	char			*opt;
	size_t			len;
	int				state;
}					t_option_map;

typedef enum		e_option_parse_state
{
	OPT_STATE_DEFAULT = 0,
	OPT_STATE_N,
	OPT_STATE_S,
	OPT_STATE_CTMO,
	OPT_STATE_DUMP,
	OPT_STATE_NUMBER,
	OPT_STATE_DISPLAY,
	OPT_STATE_STEALTH,
	OPT_STATE_CHAMPION,
	OPT_STATE_START_CYCLE,
	OPT_STATE_ROUND_LIMIT,
	OPT_STATE_PROCESS_LIMIT,
	OPT_STATE_LOG,
	OPT_ERROR
}					t_option_parse_state;

typedef struct          s_vm_option
{

	unsigned int		death[4];
    int       display;
    //t_display           display;
    int        			dump;
    int					s;
    int                 state;
    int                 *next_arg;
    int                 ac;
    char                **av;
    //TODO : put everything in one int only ?
    unsigned char       log;
    //
}                       t_vm_option;

typedef struct          s_process
{
    int                     parent_nb;
    int                     process_nb;
    unsigned int            live;
	unsigned int 			has_lived;
    unsigned int            carry;
    int            			exec_cycle;
    unsigned int            bytecode;
    int                     reg[REG_NUMBER + 1];
    int                     jump[MAX_ARGS_NUMBER];
    unsigned char           *pc;
    t_op                    *op;
    t_list                  list;
}                       t_process;

typedef struct			s_vm
{
    unsigned int            index[MAX_PLAYERS];
    int            			fd[MAX_PLAYERS];
    int            			fd_tmp[MAX_PLAYERS];
    int            			current_cycle;
	int                		cycle_to_die;
	unsigned int 			last_alive;
	unsigned int 			total_live;
	unsigned int 			nb_champion;
    unsigned char           arena[2][MEM_SIZE];
    t_vm_option             option;
    t_header                header[MAX_PLAYERS];
    t_list                  process_head;
}			            t_vm;

typedef void            (*t_func)(t_vm *, t_process *);

typedef void			(*t_state_machine)(t_vm *vm);

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
void        ft_vm_print_intro(t_vm const *vm);
void		ft_vm_print_arena(void const *data,
									size_t msize,
									size_t nb_byte,
									t_vm *vm);
t_list		*ft_vm_find_proc_nb(t_list *head, int nb);

/*
** Parse functions
*/

void        ft_vm_parse(t_vm *vm, int const ac, char **av);
void		ft_vm_parse_default(t_vm *vm);
void        ft_vm_parse_champion(t_vm *vm);
void		ft_vm_parse_n(t_vm *vm);
void		ft_vm_parse_number(t_vm *vm);
void 		ft_vm_parse_champion_repartition(t_vm *vm);
void        ft_vm_parse_display(t_vm *vm);
void        ft_vm_parse_dump(t_vm *vm);
void        ft_vm_parse_s(t_vm *vm);
void        ft_vm_parse_log(t_vm *vm);
#if 0
void        ft_vm_parse_start_c(t_vm *vm, char **av);
#endif

/*
** Read functions
*/

void       ft_vm_read_header(t_vm *vm);
void       ft_vm_read_header_magic(t_vm *vm, int i);
void       ft_vm_read_header_name(t_vm *vm, int i);
void       ft_vm_read_header_size(t_vm *vm, int i);
void       ft_vm_read_header_comment(t_vm *vm, int i);

/*
** Arena functions
*/

void       ft_vm_arena(t_vm *vm);
void       ft_vm_arena_upload(t_vm *vm);
void	   ft_vm_arena_cycle_routine(t_vm *vm);
void       ft_vm_arena_instr_routine(t_vm *vm, t_process *proc);
void       ft_vm_arena_round_check(t_vm *vm,
                                    int *cycle_end_round);

/*
** Process functions
*/

void       ft_vm_new_process(t_vm *vm,
                            const int master_nb,
                            const int process_nb,
                            const unsigned int index);
void		ft_vm_new_process_kid(t_vm *vm,
							t_process *proc,
							const unsigned int index);
void		ft_vm_close_process(t_list *node);

/*
** Instruction functions
*/

void        ft_vm_instr_fail(t_vm *vm, t_process *proc,
                            const int size,
                            const int carry_change);
void		ft_vm_instr_update_exec_cycle(t_vm *vm, t_process *proc);
int         ft_vm_instr_bytecode_check(t_process *proc);
int			ft_vm_instr_get_data(size_t size, uint8_t *pc, t_vm *vm);
int	    	ft_vm_instr_and_or_xor_routine(t_vm *vm,
                            t_process *proc,
                            unsigned char **ptr,
                            int tab[2]);
int	    	ft_vm_instr_add_sub_routine(t_vm *vm,
                            t_process *proc,
                            unsigned char **ptr,
                            int tab[3]);
void		ft_vm_instr_st_data(t_vm *vm, const unsigned char *ptr, int *reg);
/*
** Instruction set
*/

void       ft_vm_instr_live(t_vm *vm, t_process *proc);
void       ft_vm_instr_ld(t_vm *vm, t_process *proc);
void       ft_vm_instr_st(t_vm *vm, t_process *proc);
void       ft_vm_instr_add(t_vm *vm, t_process *proc);
void       ft_vm_instr_sub(t_vm *vm, t_process *proc);
void       ft_vm_instr_and(t_vm *vm, t_process *proc);
void       ft_vm_instr_or(t_vm *vm, t_process *proc);
void       ft_vm_instr_xor(t_vm *vm, t_process *proc);
void       ft_vm_instr_zjmp(t_vm *vm, t_process *proc);
void       ft_vm_instr_ldi(t_vm *vm, t_process *proc);
void       ft_vm_instr_sti(t_vm *vm, t_process *proc);
void       ft_vm_instr_fork(t_vm *vm, t_process *proc);
void       ft_vm_instr_lld(t_vm *vm, t_process *proc);
void       ft_vm_instr_lldi(t_vm *vm, t_process *proc);
void       ft_vm_instr_lfork(t_vm *vm, t_process *proc);
void       ft_vm_instr_aff(t_vm *vm, t_process *proc);

/*
** Log functions
*/

void			ft_vm_log_intro(t_vm const *vm);
void			ft_vm_log_arg(t_process const *proc);

/*
** Log set
*/

void			ft_vm_log_live(t_vm *vm,
                            t_process const *proces,
                            t_list const *it);
void			ft_vm_log_ld(t_vm *vm,
                            t_process const *proces,
                            unsigned char const *ptr,
                            const unsigned int address);
void 			ft_vm_log_st(t_vm *vm, t_process const *proc);
void 			ft_vm_log_add(t_vm *vm,
                            t_process const *proc,
                            const int add[3]);
void 			ft_vm_log_sub(t_vm *vm,
                            t_process const *proc,
                            const int sub[3]);
void 			ft_vm_log_and(t_vm *vm,
							t_process const *proc,
							unsigned char const *ptr,
							const int and[2]);
void 			ft_vm_log_or(t_vm *vm,
                            t_process const *proc,
                            unsigned char const *ptr,
                            const int or[2]);
void 			ft_vm_log_xor(t_vm *vm,
                            t_process const *proc,
                            unsigned char const *ptr,
                            const int xor[2]);
void 			ft_vm_log_zjmp(t_vm *vm, t_process const *proc);
void			ft_vm_log_ldi(t_vm *vm,
							t_process const *proc,
							unsigned char const *ptr,
   							const int tab[2]);
void            ft_vm_log_sti(t_vm *vm, t_process const *proc,
                            const int copy_at_address[2]);
void            ft_vm_log_fork(t_vm *vm,
                            t_process const *proc,
                            const int index);
void            ft_vm_log_lld(t_vm *vm, t_process const *proc,
                            unsigned char const *ptr,
                            const unsigned int value_to_load);
void            ft_vm_log_lldi(t_vm *vm, t_process const *proc,
                            unsigned char const *ptr,
                            const unsigned int address);
void            ft_vm_log_lfork(t_vm *vm,
                            t_process const *proc,
                            const int index);
void            ft_vm_log_aff(t_vm *vm, t_process const *proc);

/*
** Display functions
*/

void    		ft_vm_display_death(t_vm const *vm);
void    		ft_vm_display_pc(t_vm const *vm, t_process const *proc, const int size);

/*
** Display set
*/

void    		ft_vm_display_live(t_vm *vm, t_process const *proc,
                                    t_list const *it,
                                    const int number);
void			ft_vm_display_ld(t_vm *vm,
                                    t_process const *proces,
                                    unsigned char const *ptr,
                                    const unsigned int address);
void 			ft_vm_display_st(t_vm *vm, t_process const *proc);
void			ft_vm_display_add(t_vm *vm,
                                   t_process const *proc,
                                   const int add[3]);
void			ft_vm_display_sub(t_vm *vm,
                                  t_process const *proc,
                                  const int sub[3]);
void			ft_vm_display_and(t_vm *vm,
                                   t_process const *proc,
                                   unsigned char const *ptr,
                                   const int and[2]);
void			ft_vm_display_or(t_vm *vm,
                                   t_process const *proc,
                                   unsigned char const *ptr,
                                   const int or[2]);
void			ft_vm_display_xor(t_vm *vm,
                              t_process const *proc,
                              unsigned char const *ptr,
                              const int xor[2]);
void			ft_vm_display_sti(t_vm *vm, t_process const *proc, const int tab[2]);
void			ft_vm_display_ldi(t_vm *vm, t_process const *proc, const int tab[2], unsigned char const *ptr);
void			ft_vm_display_lld(t_vm *vm,
                                    t_process const *proc,
                                    unsigned char const *ptr,
                                    const int address);
#endif
