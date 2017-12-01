/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:24:09 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 10:31:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define MOD(x)	        ((x) < 0) ? (MEM_SIZE + ((x) % MEM_SIZE)) : ((x) % MEM_SIZE)
# define IS_INSTR(x)     ((x > 0) && (x <= REG_NUMBER))
# define IS_REG(x)		(!IS_NEG(x) && (x < REG_NUMBER))

# define LOG_OPT        (vm->option.log)
# define DISP_OPT		(vm->option.display)
# define DUMP_OPT		(vm->option.dump)

# define CARRY_CHANGE    1

# define C_PROCESS(it)	CONTAINEROF(it, t_process, list)

/*
** Define flags
*/

# define FLAG_1		(1 << 0)
# define FLAG_2		(1 << 1)
# define FLAG_4		(1 << 2)
# define FLAG_8		(1 << 3)
# define FLAG_16	(1 << 4)
# define FLAG_32	(1 << 5)

/*
** Comparisons
*/

# define DISPLAY_1   (vm->option.display & FLAG_1)
# define DISPLAY_2 (vm->option.display & FLAG_2)
# define DISPLAY_4 (vm->option.display & FLAG_4)
# define DISPLAY_8 (vm->option.display & FLAG_8)
# define DISPLAY_16 (vm->option.display & FLAG_16)
# define DISPLAY_32 (vm->option.display & FLAG_32)
/*
** Structures
*/

#if 0
typedef struct          s_display
{
    unsigned int        nb;
    //
}                       t_display;
#endif
typedef struct          s_vm_option
{
    //TODO : put everything in one int only
    unsigned char       log;
    //
    unsigned int       display;
    //t_display           display;
    unsigned int        dump;
}                       t_vm_option;

typedef struct          s_process
{
    int                     parent_nb;
    int                     process_nb;
    unsigned int            live;
    unsigned int            carry;
    unsigned int            exec_cycle;
    unsigned int            bytecode;
    int                     reg[REG_NUMBER];
    int                     jump[MAX_ARGS_NUMBER];
    unsigned char           *pc;
    t_op                    *op;
    t_list                  list;
}                       t_process;

typedef struct			s_vm
{
    unsigned int            index[MAX_PLAYERS];
    unsigned int            fd[MAX_PLAYERS];
    unsigned int            current_cycle;
    unsigned int            last_alive;
    unsigned int            checks;
	unsigned int 			nb_champion;
    unsigned char           arena[2][MEM_SIZE];
    t_vm_option             option;
    t_header                header[MAX_PLAYERS];
    t_list                  process_head;
}			            t_vm;

typedef struct			s_instr_list
{
	void			(*func)(t_vm *vm, t_process *proc);
}						t_instr_list;

/*
** Prototypes
*/

/*
** Commun function
*/
int			ft_instruction_get_data(size_t size, uint8_t *pc);

/*
** Tool and Print functions
*/
int			ft_atoi(char *str);
void        ft_vm_print_intro(t_vm *vm);
void		ft_vm_print_arena(void const *data,
									size_t msize,
									size_t nb_byte,
									t_vm *vm);
t_list		*ft_vm_find_proc_nb(t_list *head, int nb);
/*
** Parse functions
*/

void        ft_vm_parse(t_vm *vm, char **av);
void        ft_vm_parse_log(t_vm *vm, char **av);
void        ft_vm_parse_start_c(t_vm *vm, char **av);
void        ft_vm_parse_dump(t_vm *vm, char **av);
void        ft_vm_parse_display(t_vm *vm, char **av);
void        ft_vm_parse_champion(t_vm *vm, char **av);

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
                                    unsigned int *cycle_end_round,
                                    unsigned int *cycle_to_die);

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

void        ft_vm_instr_fail(t_process *proc, const int carry_change);
void		ft_vm_instr_update_exec_cycle(t_process *proc);
int         ft_vm_instr_bytecode_check(t_process *proc);
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

void			ft_vm_log_intro(t_vm *vm);
void			ft_vm_log_arg(t_process *proc);

/*
** Log set
*/

void			ft_vm_log_live(t_vm *vm, t_process *proces, t_list *it);
void			ft_vm_log_ld(t_vm *vm,
                            t_process *proces,
                            const unsigned char *ptr,
                            const unsigned int address);
void 			ft_vm_log_st(t_vm *vm, t_process *proc, const int dir);
void 			ft_vm_log_add(t_vm *vm,
                            t_process *proc,
                            const unsigned int add[3]);
void 			ft_vm_log_sub(t_vm *vm,
                            t_process *proc,
                            const unsigned int sub[3]);
void 			ft_vm_log_and(t_vm *vm,
							t_process *proc,
							const unsigned char *ptr,
							const unsigned int and[2]);
void 			ft_vm_log_or(t_vm *vm,
                            t_process *proc,
                            const unsigned char *ptr,
                            const unsigned int or[2]);
void 			ft_vm_log_xor(t_vm *vm,
                            t_process *proc,
                            unsigned char *ptr,
                            const unsigned int xor[2]);
void 			ft_vm_log_zjmp(t_vm *vm, t_process *proc);
void 			ft_vm_log_xor(t_vm *vm,
                            t_process *proc,
                            unsigned char *ptr,
                            const unsigned int xor[2]);
void			ft_vm_log_ldi(t_vm *vm,
							t_process *proc,
							unsigned char *ptr,
   							const unsigned int value_to_load);
void            ft_vm_log_sti(t_vm *vm, t_process *proc,
                            const int copy_at_address);
void            ft_vm_log_fork(t_vm *vm,
                            t_process *proc,
                            const int index);
void            ft_vm_log_lld(t_vm *vm, t_process *proc,
                            const unsigned char *ptr,
                            const unsigned int value_to_load);
void            ft_vm_log_lldi(t_vm *vm, t_process *proc,
                            const unsigned char *ptr,
                            const unsigned int address);
void            ft_vm_log_lfork(t_vm *vm,
                            t_process *proc,
                            const int index);
void            ft_vm_log_aff(t_vm *vm, t_process *proc);

/*
** Display functions
*/

void			ft_vm_display_live(t_vm *vm, t_process *proces, t_list *it);
#endif
