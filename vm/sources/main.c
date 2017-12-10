/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:30:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 20:43:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_log.h"

int				main(int ac, char **av)
{
	t_vm		vm;

	if (ac < 2)
		return (0);
	/* Initialize the main structure */
	ft_memset((void *)&vm, '\0', sizeof(t_vm));
	INIT_LIST_HEAD(vm.process_head);
	/* Parse arguments */
	++av;
	ft_vm_parse(&vm, ac, av);
	ft_printf("display : %d\n", vm.option.display);
	return (0);
	#if 0
	/* Read each champion's header */
	ft_vm_read_header(&vm);
	#if 0
	if (!vm.nb_champion)
		return (0);
	#endif
	/* Print presentation before the battle starts */
	ft_vm_print_intro(&vm);
	/* Handle the battle */
	ft_vm_arena(&vm);
	/* Close the logfile */
	vm.option.log ? ft_log_close() : 0;
	//CLOSE ALL THE PROCESSES
	#endif
	return (0);
}
