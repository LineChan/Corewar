/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 23:06:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/20 19:14:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Standard Libraries
*/
# include <stdarg.h>
# include <locale.h>
# include <wchar.h>
# include <limits.h>
# include <unistd.h>

/*
** Personal Libraries
*/
# include "ft_string.h"
# include "ft_ctype.h"

/*
** Buffer size - min : 55 (ULL in base 2)
*/
# define BUFF_MAX 0x64
# define NB_COLORS_MAX 0x20

/*
** Strings
*/
# define SIZE			(arg->p - arg->buff)
# define NB_COLOR		(arg->color_ptr)
# define TYPE			("sSpdDioOuUxXcCbB%")
# define MOD_LIST		("hljz")
# define ULL			unsigned long long
# define LL				long long
# define UP				("0123456789ABCDEFGH")
# define LOW			("0123456789abcdefgh")

/*
** Define flags
*/
# define FLAG_MINUS		(1 << 0)
# define FLAG_PLUS		(1 << 1)
# define FLAG_ZERO		(1 << 2)
# define FLAG_SPACE		(1 << 3)
# define FLAG_SHARP		(1 << 4)
# define FLAG_DOT		(1 << 5)
# define FLAG_WILD		(1 << 6)
# define FLAG_WILD_DOT	(1 << 7)
# define FLAG_WILD_DOT2	(1 << 8)

/*
** Define mods
*/
# define MOD_HH			(1 << 9)
# define MOD_H			(1 << 10)
# define MOD_LL			(1 << 11)
# define MOD_L			(1 << 12)
# define MOD_J			(1 << 13)
# define MOD_Z			(1 << 14)

/*
** Comparisons
*/
# define MINUS		(arg->flag & FLAG_MINUS)
# define PLUS		(arg->flag & FLAG_PLUS)
# define ZERO		(arg->flag & FLAG_ZERO)
# define SPACE		(arg->flag & FLAG_SPACE)
# define SHARP		(arg->flag & FLAG_SHARP)
# define DOT		(arg->flag & FLAG_DOT)
# define WILD		(arg->flag & FLAG_WILD)
# define WILD_D		(arg->flag & FLAG_WILD_DOT)
# define WILD_D2	(arg->flag & FLAG_WILD_DOT2)
# define M_HH		(arg->flag & MOD_HH)
# define M_H		(arg->flag & MOD_H)
# define M_LL		(arg->flag & MOD_LL)
# define M_L		(arg->flag & MOD_L)
# define M_J		(arg->flag & MOD_J)
# define M_Z		(arg->flag & MOD_Z)

/*
** Structures
*/
typedef struct			s_struct
{
	int					padd;
	int					dot;
	int					neg;
	int					color_ptr;
	int					fd;
	unsigned long		flag;
	char				type;
	char				rdm;
	char				*p;
	char				buff[BUFF_MAX + 1];
	va_list				ap;
}						t_struct;

typedef struct			s_printf
{
	char const			c;
	void				(*func)(t_struct *);
}						t_printf;

/*
** Prototypes
*/
int						ft_printf(const char *format, ...);
int						ft_fprintf(const int fd, const char *s, ...);
int						ft_uintlen(unsigned long int nb,
									unsigned long int base);
int						ft_intlen(long long int nb);
int						*ret(void);
void					ft_printf_write_buff(t_struct *arg);
int						ft_printf_unicode_string(t_struct *arg, wchar_t wc);
void					ft_printf_parsing(char *s, t_struct *arg);
void					ft_printf_colors(char **s, t_struct *arg);
void					ft_printf_end_colors(char **s, t_struct *arg);
char					*ft_stpcpy(char *s, const char *src);
void					ft_printf_init_struct(t_struct *arg);
void					ft_printf_analyse(char c, t_struct *arg);
void					ft_printf_find_type(char c, t_struct *arg);
void					ft_printf_string(t_struct *arg);
void					ft_printf_lc(t_struct *arg, wchar_t wc);
void					ft_printf_ls(t_struct *arg);
void					ft_printf_int(t_struct *arg);
void					ft_printf_pointer(t_struct *arg);
void					ft_printf_putnbr_p(unsigned long long p,
											t_struct *arg);
void					ft_printf_hexa(t_struct *arg);
void					ft_printf_hexa_zero(t_struct *arg);
void					ft_printf_octal(t_struct *arg);
void					ft_printf_unsigned(t_struct *arg);
void					ft_printf_modulo(t_struct *arg);
void					ft_printf_binary(t_struct *arg);
void					ft_printf_wild(t_struct *arg);
long long int			ft_printf_convert_id(t_struct *arg);
unsigned long long		ft_printf_convert_unsigned(t_struct *arg);

#endif
