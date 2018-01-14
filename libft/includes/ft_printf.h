/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/01 22:00:05 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>

/*
 * brief      Enum for default file descriptor: stdin, stdout and stderr
 */
typedef enum		e_printf_fd
{
	ft_stdin = 0,
	ft_stdout,
	ft_stderr
}					t_printf_fd;

int32_t				ft_printf(char const *format, ...);
int32_t				ft_fprintf(int32_t const fd, char const *format, ...);
int32_t				ft_sprintf(char *buf, char const *format, ...);
int32_t				ft_snprintf(char *buf, size_t n, char const *format, ...);
int32_t				ft_asprintf(char **ptr, char const *format, ...);

int32_t				ft_vprintf(char const *format, va_list ap);
int32_t				ft_vfprintf(int const fd, char const *format, va_list ap);
int32_t				ft_vsprintf(char *buf, char const *format, va_list ap);
int32_t				ft_vsnprintf(char *buf, size_t n, char const *format, va_list ap);
int32_t				ft_vasprintf(char **ptr, char const *format, va_list ap);

#endif
