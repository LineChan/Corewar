/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:41:51 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"
#include "ft_printf.h"

int		ft_vsnprintf(char *buf, size_t n, char const *format, va_list ap)
{
	t_pf_buf	p;

	p.nb = 0;
	p.limit = n;
	p.buffer = buf;
	p.buffer_malloc = PF_ALLOC_OFF;
	ft_pf_engine(&p, format, ap);
	return (n - p.limit);
}
