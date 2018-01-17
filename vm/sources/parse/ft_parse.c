/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:05:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/17 02:10:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

static const t_state_machine	g_option_state_machine[] =
{
	[OPT_STATE_DEFAULT] = &ft_parse_default,
	//[OPT_STATE_N] = &ft_parse_n,
	#if 0
	[OPT_STATE_S] = &ft_vm_parse_s,
	[OPT_STATE_CTMO] = &ft_option_parse_ctmo,
	#endif

	#if 0
	[OPT_STATE_DUMP] = &ft_vm_parse_dump,
	#endif
	[OPT_STATE_NUMBER] = &ft_parse_nb,
	//[OPT_STATE_DISPLAY] = &ft_vm_parse_display,

	#if 0
	[OPT_STATE_STEALTH] = &ft_option_parse_stealth,
	#endif
	[OPT_STATE_PROC] = &ft_parse_proc,
	#if 0
	[OPT_STATE_START_CYCLE] = &ft_option_parse_start_cycle,
	[OPT_STATE_ROUND_LIMIT] = &ft_option_parse_round_limit,
	[OPT_STATE_PROCESS_LIMIT] = &ft_vm_process_limit,
	#endif
	//[OPT_STATE_LOG] = &ft_vm_parse_log,
};

void			ft_parse(t_vm *vm, int const ac, char **av)
{
	t_parse		parse;

	/* Initialize the State Machine */
	parse.ac = ac - 1;
	parse.av = av;
	parse.state = OPT_STATE_DEFAULT;
	/* State Machine loop */
	while ((0 != parse.ac) && (0 != parse.av))
		g_option_state_machine[parse.state](vm, &parse);
	/* The program exits if no processes were upload */
	if (0 == vm->nb_proc)
		ft_exit("No process uploaded");
	/* Order processes */
	//ft_parse_proc_repartition(vm);
}
