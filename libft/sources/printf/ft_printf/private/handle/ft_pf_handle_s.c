/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:40:18 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

static int32_t	ft_pf_set_w(char *buf, int32_t limit, wchar_t const *wc, int32_t precision)
{
	int32_t		len;
	char		*it;

	it = buf;
	while (0 != *wc && (it - buf) < limit)
	{
		len = ft_pf_wctomb(it, *wc++);
		if (0 <= precision && len > precision)
			break ;
		precision -= len;
		it += len;
	}
	*it = 0;
	return (it - buf);
}

static void		ft_pf_handle_w(t_pf_buf *p, t_printf *pf)
{
	/*
		+8 assert wctomb will not overflow if limit is near 0.
		It assert aswell the memory is aligned. */
	static char	tmp[0x1000 + 8];
	int32_t		byte_len;
	wchar_t		*s;

	s = pf->arg.p;
	if (pf->precision > pf->width)
		pf->width = 0;
	byte_len = ft_pf_set_w(tmp, 0x1000, s, pf->precision);
	ft_pf_pre_padd(p, byte_len, pf);
	ft_pf_buffer_push(p, tmp, byte_len);
	ft_pf_post_padd(p, byte_len, pf);
}

void			ft_pf_handle_s(t_pf_buf *p, t_printf *pf)
{
	char	*s;
	size_t	len;

	s = pf->arg.p;
	if (0 == s)
		s = "(null)";
	else if (PF_l == pf->length || (~pf->specifier & 32))
		return (ft_pf_handle_w(p, pf));
	len = strnlen(s, pf->precision);
	ft_pf_pre_padd(p, len, pf);
	ft_pf_buffer_push(p, s, len);
	ft_pf_post_padd(p, len, pf);
}
