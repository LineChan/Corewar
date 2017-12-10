/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_default.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:28:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 20:24:30 by mvillemi         ###   ########.fr       */
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
	{ "-dump", 5, OPT_STATE_DUMP },
	#if 0
	{ "-ctmo", 5, OPT_STATE_CTMO },
	#endif
	{ "-s", 2, OPT_STATE_S },
	{ "-n", 2, OPT_STATE_N }
};

void			ft_vm_parse_default(t_vm *vm)
{
	size_t		i;

	i = 0;
	while (i < SIZEOF_TAB(g_option_map))
	{
		if (0 == ft_strncmp(*vm->option.av,
							g_option_map[i].opt,
							g_option_map[i].len))
		{
			vm->option.state = g_option_map[i].state;
			return ;
		}
		++i;
	}
	vm->option.state = OPT_STATE_CHAMPION;
}
