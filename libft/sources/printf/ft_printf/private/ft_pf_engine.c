/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/03 17:09:56 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

static const t_pf_handle	g_pf_specifier_table[256] =
{
	PF_SPECIFIER('s') = PF_VALUE(&ft_pf_handle_s),
	PF_SPECIFIER('p') = PF_VALUE(&ft_pf_handle_p),
	PF_SPECIFIER('d') = PF_VALUE(&ft_pf_handle_d),
	PF_SPECIFIER('i') = PF_VALUE(&ft_pf_handle_d),
	PF_SPECIFIER('o') = PF_VALUE(&ft_pf_handle_o),
	PF_SPECIFIER('u') = PF_VALUE(&ft_pf_handle_u),
	PF_SPECIFIER('x') = PF_VALUE(&ft_pf_handle_x),
	PF_SPECIFIER('c') = PF_VALUE(&ft_pf_handle_c),
	PF_SPECIFIER('n') = PF_VALUE(&ft_pf_handle_n),
	PF_SPECIFIER('e') = PF_VALUE(&ft_pf_handle_e),
	PF_SPECIFIER('f') = PF_VALUE(&ft_pf_handle_f),
	PF_SPECIFIER('g') = PF_VALUE(&ft_pf_handle_g),
	PF_SPECIFIER('a') = PF_VALUE(&ft_pf_handle_a),
	PF_SPECIFIER('k') = PF_VALUE(&ft_pf_handle_k),
	PF_SPECIFIER('b') = PF_VALUE(&ft_pf_handle_b),
	PF_SPECIFIER('r') = PF_VALUE(&ft_pf_handle_r),
	PF_SPECIFIER('m') = PF_VALUE(&ft_pf_handle_m)
};

static char	*ft_pf_find(char const *p, char const *accept)
{
	char	fast_lookup[256] = { 0 };
	int		c;

	/* Set on every byte that appear in accept */
	while (0 != (c = *accept++))
		fast_lookup[c] = 1;
	/* run p until we find a non-null byte in table */
	while (0 != (c = *p) && 0 == fast_lookup[c])
		++p;
	return ((char *)p);
}

static void	ft_pf_apply(t_pf_buf *p, char **cursor, t_printf *pf, va_list ap)
{
	++(*cursor);
	pf->flags = ft_pf_parse_flags(cursor);
	pf->width = ft_pf_parse_width(cursor, ap, pf);
	pf->precision = ft_pf_parse_precision(cursor, ap, pf);
	if (EXIT_SUCCESS == ft_pf_getarg(cursor, pf, ap))
		g_pf_specifier_table[pf->specifier | 32](p, pf);
	else
	{
		ft_pf_pre_padd(p, 1, pf);
		ft_pf_buffer_add(p, **cursor);
		ft_pf_post_padd(p, 1, pf);
	}	
}

void		ft_pf_engine(t_pf_buf *p, char const *format, va_list ap)
{
	t_printf		pf;
	char			*cursor;

	while (0 != (cursor = ft_pf_find(format, "{%}"))[0])
	{
		if ('%' == *cursor)
		{
			if (0 == cursor[1])
				break ;
			ft_pf_buffer_push(p, format, cursor - format);
			ft_pf_apply(p, &cursor, &pf, ap);
		}
		else
		{
			ft_pf_buffer_push(p, format, cursor - format);
			if (EXIT_FAILURE == ft_pf_handle_color(p, &cursor))
				ft_pf_buffer_add(p, *cursor);
		}
		format = cursor + 1;
	}
	ft_pf_buffer_push(p, format, cursor - format);
}
