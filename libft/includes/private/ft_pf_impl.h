/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_impl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/09 23:15:02 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PF_PARSE_H
# define FT_PF_PARSE_H

# include <stdint.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <wchar.h>

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# define PF_ALLOC_OFF		0
# define PF_ALLOC_ON		1
# define PF_MIN_CAPACITY	8

typedef enum		e_pf_arg_type
{
	PF_ERROR = 0,
	PF_l,
	PF_ll,
	PF_h,
	PF_hh,
	PF_L,
	PF_j,
	PF_z,
	PF_t,
	PF_NO_ARG,
	PF_ERRNO,
	PF_PTR,
	PF_UINTPTR,
	PF_PTRDIFF,
	PF_SIZET,
	PF_INTMAX,
	PF_UINTMAX,
	PF_INT8,
	PF_INT16,
	PF_INT32,
	PF_INT64,
	PF_UINT8,
	PF_UINT16,
	PF_UINT32,
	PF_UINT64,
	PF_DOUBLE,
	PF_LDOUBLE,
	PF_DATE
}					t_pf_arg_type;

typedef union		s_pf_arg
{
	uintmax_t		i;
	long double		d;
	void			*p;
}					t_pf_arg;

typedef struct		s_pf_buf
{
	char			*buffer;
	size_t			limit;
	size_t			nb;
	int				buffer_malloc;
	size_t			alloc_capacity;
}					t_pf_buf;

typedef struct		s_printf
{
	int32_t			flags;
	int32_t			width;
	int32_t			precision;
	int32_t			length;
	int32_t			specifier;
	t_pf_arg		arg;
}					t_printf;

void				ft_pf_buffer_add(t_pf_buf *p, int c);
void				ft_pf_buffer_push(t_pf_buf *p, char const *data, size_t size);
int					ft_pf_wctomb(char *buf, wchar_t wc);

# define PF_FLAG_MINUS  	(1 << 0)
# define PF_FLAG_PLUS  		(1 << 1)
# define PF_FLAG_SPACE  	(1 << 2)
# define PF_FLAG_POUND  	(1 << 3)
# define PF_FLAG_ZERO		(1 << 4)
# define PF_FLAG_COMMA  	(1 << 5)
# define PF_FLAG_DOLLAR		(1 << 6)
# define PF_FLAG_SIGNED		(1 << 7)

# define PF_SPECIFIER(c)	[c]
# define PF_LENGTH(c)		[c]
# define PF_VALUE(v)		v

int32_t				ft_pf_parse_flags(char **fmt);
int32_t				ft_pf_parse_width(char **fmt, va_list ap, t_printf *pf);
int32_t				ft_pf_parse_precision(char **fmt, va_list ap, t_printf *pf);
int32_t				ft_pf_getarg(char **fmt, t_printf *pf, va_list ap);

void				ft_pf_pre_padd(t_pf_buf *p, size_t n, t_printf *pf);
void				ft_pf_post_padd(t_pf_buf *p, size_t n, t_printf *pf);

void				ft_pf_engine(t_pf_buf *p, char const *format, va_list ap);

typedef	void		(*t_pf_handle)(t_pf_buf *, t_printf *);

void				ft_pf_handle_a(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_b(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_c(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_d(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_e(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_f(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_g(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_k(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_m(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_n(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_o(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_p(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_s(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_u(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_x(t_pf_buf *p, t_printf *pf);
void				ft_pf_handle_r(t_pf_buf *p, t_printf *pf);
int					ft_pf_handle_color(t_pf_buf *p, char **cursor);

#endif
