/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:05:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 00:00:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

#if 0
static char const	*g_subject_usage[] =
{
	"\nUsage: corewar <options> champion.cor [...]",
	"### CONTESTANT ######################################################",
	"your_champion.cor: Champion compiled with the asm",
	"-n N:              Set champion number for the next champion",
	"### LIMIT ###########################################################",
    "-process-limit N:  Use a pool of maximum N processes",
    "-round-limit N:    Play maximum of N rounds",
    "-start-cycle N:    Start battle when cycle counter reach this limit",
    "-ctmo N:           Champions play in their area instead of the arena",
    "                   area for the N first cycles",
    "                   The instruction (gtmo) is implemented in this mode",
	"### DUMP ############################################################",
    "-stealth:          Hides the real content of the memory",
	"-dump N:           Dumps memory after N cycles then exits",
    "-s N:              Runs N cycles, dumps memory, pauses, then repeats",
	"### TEXT OUTPUT MODE ################################################",
    "-display:          0:  Show only essentials",
    "                   1:  Show lives",
    "                   2:  Show cycles",
    "                   4:  Show operations",
    "                   8:  Show deaths",
    "                   16: Show PC movements (Except for jumps)",
    "                   32: Display ncurses mode"
};

void				ft_option_usage(void)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_subject_usage) / sizeof(g_subject_usage[0]))
	{
		ft_fprintf(ft_stderr, "%s\n", g_subject_usage[i]);
		++i;
	}
	exit(EXIT_FAILURE);
}
#endif

static const t_state_machine	g_option_state_machine[] =
{
	[OPT_STATE_DEFAULT] = &ft_parse_default,
	[OPT_STATE_N] = &ft_parse_n,
	[OPT_STATE_AFF] = &ft_parse_aff,
	#if 0
	[OPT_STATE_S] = &ft_vm_parse_s,
	[OPT_STATE_CTMO] = &ft_option_parse_ctmo,
	#endif

	[OPT_STATE_DUMP] = &ft_parse_dump,
	#if 0
	#endif
	[OPT_STATE_NUMBER] = &ft_parse_nb,
	[OPT_STATE_DISPLAY] = &ft_parse_display,
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
