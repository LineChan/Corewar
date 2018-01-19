/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:30:22 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 11:14:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_log.h"

#include "ft_instruction.h"
#include "ft_printf.h"
int				main(int ac, char **av)
{
	t_vm		vm;

	if (ac < 2)
		return (0);
	/* Initialize the main structure */
	ft_memset((void *)&vm, '\0', sizeof(t_vm));
	INIT_LIST_HEAD(vm.proc_head);
	/* Parse arguments */
	++av;
	ft_parse(&vm, ac, av);
	/* Read each champion's header */
	ft_header(&vm);
	/* Print presentation before the battle starts */
	ft_print_intro(&vm);
	/* Handle the battle */
	ft_arena(&vm);
	/* Free the processes' list */
	ft_del_proc_list(&vm);
	#if 0
	int i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_printf("name : %s comment : %s, size : %d\n",
			vm.header[i].prog_name,
			vm.header[i].comment,
			vm.header[i].prog_size);
		++i;
	}
	#endif
	#if 0
	t_list *it;
	it = vm.proc_head.next;
	while (it != NULL)
	{
		ft_printf("name : %s, comment : %s, size : %d \n",
				C_PROCESS(it)->prog_name,
				C_PROCESS(it)->comment,
				C_PROCESS(it)->prog_size);
		it = it->next;
	}
	#endif
	#if 0
	/* Print presentation before the battle starts */
	ft_vm_print_intro(&vm);
	/* Handle the battle */
	ft_vm_arena(&vm);
	/* Close the logfile */
	if (vm.option.log)
		ft_log_close();
	ft_vm_del_list(&vm);
	#endif
	return (0);
}
