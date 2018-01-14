/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/03 13:25:23 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

static const int	g_pf_flags_table[256] =
{
	['-'] = PF_FLAG_MINUS,
	['+'] = PF_FLAG_PLUS,
	[' '] = PF_FLAG_SPACE,
	['#'] = PF_FLAG_POUND,
//	['$'] = PF_FLAG_DOLLAR,
	['0'] = PF_FLAG_ZERO,
//	['\''] = PF_FLAG_COMMA
};

int		ft_pf_parse_flags(char **fmt)
{
	int		flags;
	int		lookup;
	int		cursor;

	flags = 0;
	cursor = **fmt;
	lookup = g_pf_flags_table[cursor];
	while (0 != lookup)
	{
		cursor = *++(*fmt);
		flags |= lookup;
		lookup = g_pf_flags_table[cursor];
	}
	return (flags);
}
