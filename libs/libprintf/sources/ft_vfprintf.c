/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:22:54 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 12:38:22 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include <unistd.h>

int		ft_vfprintf(int fd, char const *format, va_list ap)
{
	char		buf[FT_PRINTF_BUFFSIZE];
	char		*p;
	int			n;
	int			r;

	p = buf;
	ft_memset((void *)buf, 0, FT_PRINTF_BUFFSIZE);
	n = ft_vsprintf(p, format, ap);
	r = write(fd, buf, ft_strlen(buf));
	if (r != n)
		return (-1);
	return (n);
}
