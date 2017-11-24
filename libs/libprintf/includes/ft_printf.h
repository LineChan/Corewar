/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:14:32 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 12:39:16 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

/*
** Printf default file_descriptor
*/
typedef enum	e_printf_fd
{
	ft_stdin = 0,
	ft_stdout,
	ft_stderr
}				t_printf_fd;

/*
** This implementation of printf do not allocate memory.
** If you might print more thant 4096 chararacters, you should
** use the sprintf function family
*/
# define FT_PRINTF_BUFFSIZE		(0x1000)

/*
** Print on stdout
**	This function doesn't alloc memory,
**	so it shouldn't handle more than 4096 chars
*/
int				ft_printf(char const *format, ...);

/*
** Print on file_descriptor fd.
**	This function doesn't alloc memory,
**	so it shouldn't handle more than 4096
*/
int				ft_fprintf(int const fd, char const *format, ...);

/*
** Print on file_descriptor fd using va_list.
**	This function doesn't alloc memory,
**	so it shouldn't handle more than 4096
*/
int				ft_vfprintf(int fd, char const *format, va_list ap);

/*
** Print on string
**	This function does not alloc memory.
*/
int				ft_sprintf(char *buf, char const *format, ...);

/*
** Print on string using va_list
**	This function does not alloc memory, and print only INT_MAX + 1 chars max.
*/
int				ft_vsprintf(char *buf, char const *format, va_list ap);

/*
** Print on string using va_list
**	This function does not alloc memory.
*/
int				ft_vsnprintf(char *buf, size_t n, char const *fmt, va_list ap);

#endif
