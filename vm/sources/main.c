/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:30:22 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/13 15:24:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_log.h"

//TODO : libs
#include "ft_printf.h"
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
	/* Read each champion's header */
	ft_vm_read_header(&vm);
	/* Print presentation before the battle starts */
	ft_vm_print_intro(&vm);
	/* Handle the battle */
	ft_vm_arena(&vm);
	/* Close the logfile */
	if (vm.option.log)
		ft_log_close();
	ft_vm_del_list(&vm);
	return (0);
}
