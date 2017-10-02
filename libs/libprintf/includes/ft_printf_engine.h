/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_engine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:14:32 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 23:09:04 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_ENGINE_H
# define FT_PRINTF_ENGINE_H

/*
** Include size_t
*/
# include <stdio.h>

/*
** Include va_list
*/
# include <stdarg.h>

/*
** include extended type
*/
# include <stdint.h>

/*
** Printf parser options
*/
# define FT_P_LEFT			(0x01)
# define FT_P_PLUS			(0x02)
# define FT_P_SPACE			(0x04)
# define FT_P_HEXPREP		(0x08)
# define FT_P_ZEROPAD		(0x10)
# define FT_P_SIGN			(0x20)
# define FT_P_UPPERCASE		(0x40)
# define FT_P_NEGATIV		(0x80)
# define FT_P_LOWER_DIGIT	("0123456789abcdefghijklmnopqrstuvwxyz")
# define FT_P_UPPER_DIGIT	("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ")

/*
** This structure handle printf options like padding, precisions...
*/
typedef struct				s_printf_syntax
{
	int						base;
	int						flags;
	int						width;
	int						precision;
	int						qualifier;
}							t_printf_syntax;

/*
** This structure is used to declare functions that handles chars.
*/
typedef struct				s_printf_func
{
	char					c;
	void					(*f_handle)(char **, t_printf_syntax *, va_list);
}							t_printf_func;

/*
** Mantis
*/
typedef struct				s_printf_float
{
	uint32_t				low;
	uint32_t				high;
}							t_printf_float;

/*
** fuck the norm
*/
typedef struct				s_printf_parsefloat
{
	char					*fdigits;
	char					cvtbuf[80];
	int						decpt;
	int						sign;
	int						exp;
	int						pos;
	int						capexp;
	int						magnitude;
	char					*p1;
	char					*p2;
	int						count;
	double					t1;
	double					t2;
}							t_printf_parsefloat;

/*
** Convert float
*/
char						*ft_printf_float_convert(
								double arg,
								int ndigits,
								t_printf_parsefloat *pf,
								int eflag
);

/*
** Parse float number into buffer.
*/
void						ft_printf_parse_float(
								double value,
								char *buffer,
								char c,
								t_printf_syntax *pf
);

/*
** Handle float number
*/
void						ft_printf_handle_float(
								char **p,
								char c,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Handle integer number (as uint64_t)
*/
void						ft_printf_handle_integer(
								char **p,
								t_printf_syntax *pf,
								uint64_t n
);

/*
** Handle unsigned
*/
void						ft_printf_handle_unsigned(
								char **p,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Handle signed
*/
void						ft_printf_handle_signed(
								char **p,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Handle IPv4 and IPv6 address, this is still a bullshit option
*/
void						ft_printf_handle_address(
								char **p,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Handle string and wstring.
*/
void						ft_printf_handle_string(
								char **p,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Handle char and wchar
*/
void						ft_printf_handle_char(
								char **p,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Handle Roman number (uint16_t max size)
*/
void						ft_printf_handle_roman(
								char **p,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Handle date using time_t and ctime
*/
void						ft_printf_handle_date(
								char **p,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Handle list of color "{cyan}...{none}"
** Handle color depth	"{cyan:to{red:to}to}"
*/
int							ft_printf_handle_color(
								char **p,
								char const **format
);

/*
** Parse printf options into t_printf_syntax.
*/
void						ft_printf_parse(
								char const **s,
								t_printf_syntax *pf,
								va_list ap
);

/*
** Add left padding in p
*/
void						ft_printf_prepadd(
								char **p,
								size_t n,
								t_printf_syntax *pf
);

/*
** Add right padding in p
*/
void						ft_printf_postpadd(
								char **p,
								size_t n,
								t_printf_syntax *pf
);

/*
** Printf main engine, parse and select which handle functions to call.
*/
void						ft_printf_engine(
								char *p,
								char const *format,
								va_list ap
);

#endif
