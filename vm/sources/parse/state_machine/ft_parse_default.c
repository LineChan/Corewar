/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:49:14 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 13:26:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

static const t_option_map	g_option_map[] =
{
	#if 0
	{ "-process-limit", 14, OPT_STATE_PROCESS_LIMIT },
	{ "-round-limit", 12, OPT_STATE_ROUND_LIMIT },
	{ "-start-cycle", 12, OPT_STATE_START_CYCLE },
	{ "-stealth", 8, OPT_STATE_STEALTH },
	#endif
	{ "-display", 8, OPT_STATE_DISPLAY },
	{ "-v", 2, OPT_STATE_DISPLAY },
	{ "-a", 2, OPT_STATE_AFF },
	{ "-dump", 5, OPT_STATE_DUMP },
	#if 0
	{ "-ctmo", 5, OPT_STATE_CTMO },
	#endif
	{ "-s", 2, OPT_STATE_S },
	{ "-n", 2, OPT_STATE_N },
	//{"--log", 5, OPT_STATE_LOG}
	{ "--help", 6, OPT_STATE_HELP},
};

void			ft_parse_default(t_vm *vm, t_parse *parse)
{
	size_t		i;

	(void)vm;
	i = 0;
	/* Search from the option in the array */
	while (i < SIZEOF_TAB(g_option_map))
	{
		if (0 == ft_strncmp(*parse->av,
							g_option_map[i].opt,
							g_option_map[i].len))
		{
			/* Assign the corresponding state and quit */
			parse->state = g_option_map[i].state;
			return ;
		}
		++i;
	}
	/* If no option was found, the argument must be a process */
	parse->state = OPT_STATE_PROC;
}
