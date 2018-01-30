/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:17:48 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 13:25:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

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

void			ft_parse_help(t_vm *vm, t_parse *parse)
{
	(void)vm;
	(void)parse;
	size_t	i;

	i = 0;
	while (i < sizeof(g_subject_usage) / sizeof(g_subject_usage[0]))
	{
		ft_fprintf(ft_stderr, "%s\n", g_subject_usage[i]);
		++i;
	}
	exit(EXIT_FAILURE);
}
