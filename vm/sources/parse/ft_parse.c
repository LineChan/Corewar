/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:05:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/02/01 23:14:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
static const t_state_machine	g_option_state_machine[] =
{
	[OPT_STATE_DEFAULT] = &ft_parse_default,
	[OPT_STATE_N] = &ft_parse_n,
	[OPT_STATE_AFF] = &ft_parse_aff,
	[OPT_STATE_S] = &ft_parse_s,
	[OPT_STATE_DUMP] = &ft_parse_dump,
	[OPT_STATE_NUMBER] = &ft_parse_nb,
	[OPT_STATE_DISPLAY] = &ft_parse_display,
	[OPT_STATE_STEALTH] = &ft_parse_stealth,
	[OPT_STATE_PROC] = &ft_parse_proc,
	[OPT_STATE_START_CYCLE] = &ft_parse_start_cycle,
	[OPT_STATE_ROUND_LIMIT] = &ft_parse_round_limit,
	[OPT_STATE_PROCESS_LIMIT] = &ft_parse_proc_limit,
	[OPT_STATE_HELP] = &ft_parse_help,
};

void			ft_parse(t_vm *vm, int const ac, char **av)
{
	t_parse		parse;

	/* Initialize the State Machine */
	ft_memset((void *)&parse, 0, sizeof(t_parse));
	parse.ac = ac - 1;
	parse.av = av + 1;
	parse.state = OPT_STATE_DEFAULT;
	/* State Machine loop */
	while ((0 != parse.ac) && (0 != parse.av))
		g_option_state_machine[parse.state](vm, &parse);
	/* The program exits if no processes were upload */
	if (0 == vm->nb_proc)
		ft_exit("No process uploaded");
	/* Order processes */
	ft_parse_proc_repartition(vm, &parse);
}
