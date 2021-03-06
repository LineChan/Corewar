/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:49:14 by mvillemi          #+#    #+#             */
/*   Updated: 2018/02/01 23:24:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

static const t_option_map	g_option_map[] =
{
	{ "-process-limit", 14, OPT_STATE_PROCESS_LIMIT },
	{ "-round-limit", 12, OPT_STATE_ROUND_LIMIT },
	{ "-start-cycle", 12, OPT_STATE_START_CYCLE },
	{ "-stealth", 8, OPT_STATE_STEALTH },
	{ "-display", 8, OPT_STATE_DISPLAY },
	{ "-v", 2, OPT_STATE_DISPLAY },
	{ "-a", 2, OPT_STATE_AFF },
	{ "-dump", 5, OPT_STATE_DUMP },
	{ "-s", 2, OPT_STATE_S },
	{ "-n", 2, OPT_STATE_N },
	{ "-help", 5, OPT_STATE_HELP},
};

void			ft_parse_default(t_vm *vm, t_parse *parse)
{
	size_t		i;

	(void)vm;
	i = 0;
	/* Look for the options in the array */
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
