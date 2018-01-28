/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:30:22 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/28 22:52:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

#include "ft_printf.h"
int				main(int ac, char **av)
{
	t_vm		vm;

	if (ac < 2)
		return (0);
	/* Initialize the main structure */
	//ft_printf("coucou 1\n");
	ft_memset((void *)&vm, 0, sizeof(t_vm));
	INIT_LIST_HEAD(vm.proc_head);
	/* Parse arguments */
	ft_parse(&vm, ac, av);
	/* Read each champion's header */
	ft_header(&vm);
	/* Print presentation before the battle starts */
	ft_print_intro(&vm);
	/* Handle the battle */
	ft_arena(&vm);
	/* Free the processes' list */
	ft_del_proc_list(&vm);
	if (vm.opt.display & FLAG_32)
		ft_visual_end(&vm.visual);
	return (0);
}
