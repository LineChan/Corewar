/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:41:36 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"
#include "ft_printf.h"
#include <stdlib.h>

int		ft_vasprintf(char **ptr, char const *format, va_list ap)
{
	t_pf_buf	p;

	p.nb = 0;
	p.buffer_malloc = PF_ALLOC_ON;
	p.alloc_capacity = PF_MIN_CAPACITY;
	p.buffer = (char *)malloc(p.alloc_capacity * sizeof(char));
	ft_pf_engine(&p, format, ap);
	*ptr = p.buffer;
	return (p.nb);
}
