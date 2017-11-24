/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:22:54 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/16 20:34:17 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include <unistd.h>

int		ft_fprintf(int const fd, char const *format, ...)
{
	char		buf[FT_PRINTF_BUFFSIZE];
	char		*p;
	va_list	ap;
	int			n;
	int			r;

	p = buf;
	ft_memset((void *)buf, 0, FT_PRINTF_BUFFSIZE);
	va_start(ap, format);
	n = ft_vsprintf(p, format, ap);
	va_end(ap);
	r = write(fd, p, ft_strlen(p));
	if (r != n)
		return (-1);
	return (n);
}
