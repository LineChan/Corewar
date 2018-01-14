/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:38:59 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

typedef struct			s_pf_color
{
	char				*format;
	size_t				flen;
	char				*color;
	size_t				clen;
}						t_pf_color;

static const t_pf_color	g_pf_color[16] =
{
	{ "{none",    5, "\033[0m",    4},
	{ "{bold",    5, "\033[1m",    4},
	{ "{black",   6, "\033[30m",   5},
	{ "{red",     4, "\033[31m",   5},
	{ "{green",   6, "\033[32m",   5},
	{ "{yellow",  7, "\033[33m",   5},
	{ "{blue",    5, "\033[34m",   5},
	{ "{pink",    5, "\033[35m",   5},
	{ "{cyan",    5, "\033[36m",   5},
	{ "{bblack",  7, "\033[30;1m", 7},
	{ "{bred",    5, "\033[31;1m", 7},
	{ "{bgreen",  7, "\033[32;1m", 7},
	{ "{byellow", 8, "\033[33;1m", 7},
	{ "{bblue",   6, "\033[34;1m", 7},
	{ "{bpink",   6, "\033[35;1m", 7},
	{ "{bcyan",   6, "\033[36;1m", 7}
};

static const t_pf_color	*g_pf_color_stack[0x40] =
{
	&g_pf_color[0]
};

static int	ft_pf_lbracket(t_pf_buf *p, char **cursor, int *sp)
{
	t_pf_color const	*clr;
	size_t				i;

	if ('{' == **cursor)
	{
		i = 0;
		while (i < (sizeof(g_pf_color) / sizeof(0[g_pf_color])))
		{
			clr = &g_pf_color[i++];
			if (0 == strncmp(*cursor, clr->format, clr->flen))
			{
				if (':' == (*cursor)[clr->flen] || '}' == (*cursor)[clr->flen])
				{
					if (':' == (*cursor)[clr->flen] && 0x3f > *sp)
						g_pf_color_stack[++(*sp)] = clr;
					ft_pf_buffer_push(p, clr->color, clr->clen);
					*cursor += clr->flen;
					return (EXIT_SUCCESS);
				}
			}
		}
	}
	return (EXIT_FAILURE);
}

static int	ft_pf_rbracket(t_pf_buf *p, char **cursor, int *sp)
{
	t_pf_color const	*clr;

	if ('}' == **cursor && '\\' != (*cursor)[-1] && 0 < *sp)
	{
		g_pf_color_stack[(*sp)--] = &g_pf_color[0];
		clr = g_pf_color_stack[*sp];
		ft_pf_buffer_push(p, clr->color, clr->clen);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int			ft_pf_handle_color(t_pf_buf *p, char **cursor)
{
	static int	sp = 0;

	if (EXIT_SUCCESS == ft_pf_lbracket(p, cursor, &sp))
		return (EXIT_SUCCESS);
	if (EXIT_SUCCESS == ft_pf_rbracket(p, cursor, &sp))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
