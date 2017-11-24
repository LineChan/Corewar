/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:24:09 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/24 18:02:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VM_H
# define FT_VM_H

/*
** Personnal Libraries
*/

# include "op.h"
# include "ft_list.h"

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

# define	MOD(x)	((x) < 0) ? (MEM_SIZE + ((x) % MEM_SIZE)) : ((x) % MEM_SIZE)

# define    LOG_OPT         (vm->option.log)

# define C_PROCESS(it)      CONTAINEROF(it, t_process, list)

/*
** Structures
*/
typedef struct          s_vm_option
{
    unsigned char       log;
    unsigned int        start_c;
    unsigned int        dump;
}                       t_vm_option;

typedef struct          s_process
{
    int                     master_nb;
    int                     process_nb;
    unsigned int            live;
    unsigned int            carry;
    unsigned int            exec_cycle;
    unsigned char           *pc;
    int                     reg[REG_NUMBER];
    t_list          list;
}                       t_process;

typedef struct			s_vm
{
    unsigned int            index[MAX_PLAYERS];
    unsigned int            fd[MAX_PLAYERS];
    unsigned int            cycle_to_die;
    unsigned int            last_alive;
    unsigned int            checks;
    unsigned char           arena[2][MEM_SIZE];
    t_vm_option             option;
    t_header                header[MAX_PLAYERS];
    t_list                  process_head;
}			            t_vm;

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

/*
** Parse functions
*/

void        ft_vm_parse(t_vm *vm, char **av);
void        ft_vm_parse_log(t_vm *vm, char **av);
void        ft_vm_parse_start_c(t_vm *vm, char **av);
void        ft_vm_parse_dump(t_vm *vm, char **av);
void        ft_vm_parse_champion(t_vm *vm, char **av);

/*
** Read functions
*/

void       ft_vm_read_header(t_vm *vm, int *nb_champion);
void       ft_vm_read_header_magic(t_vm *vm, int i);
void       ft_vm_read_header_name(t_vm *vm, int i);
void       ft_vm_read_header_size(t_vm *vm, int i);
void       ft_vm_read_header_comment(t_vm *vm, int i);

/*
** Arena functions
*/

void       ft_vm_arena(t_vm *vm, int *nb_champion);
void       ft_vm_arena_upload(t_vm *vm, const int nb_champion);

/*
** Process functions
*/

void       ft_vm_new_process(t_vm *vm,
                            const int master_nb,
                            const int process_nb,
                            unsigned int index);
#endif
