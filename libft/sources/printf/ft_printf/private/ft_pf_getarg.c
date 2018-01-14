/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_getarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/02 02:37:01 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

/*
 * brief	State machine
 * 
 * 			That state machine give me the type and the length
 * 			of the argument. g_states is a 2D array, for the
 * 			couple length-specifier
 * 			
 * 			Working example: "%lld"
 * 				first step:
 * 			 		state = g_states[0]['l'];
 * 			   	second step:
 * 				   	state = g_states[PF_l]['l'];
 * 			    third step:
 * 				   	state = g_states[PF_ll]['d'];
 * 			    At this time, state is higher than PF_SEPARATOR.
 * 		
 * 			Error example:	"%hhp"
 * 				first step:
 * 					state = g_states[0]['h'];
 * 				second step:
 * 					state = g_states[PF_h]['h'];
 * 				third step:
 * 					state = g_states[PF_hh]['p'];
 * 				At this time, state is equal to PF_ERROR, that
 * 				mean either we don't handle this specifier or
 * 				the specifier is not compatible with the length.
 * 				
 * 			Complexity: O(n)
 * 			Space:		2304 bytes
 * 						can be reduce to 2048 bytes but I'm not sure
 * 						yet that 'z' and 't' length are equals on
 * 						most arch.
 * 					 	
 * 					 	printf("%d", sizeof(size_t) == sizeof(ptrdiff_t));
 */
static const uint8_t	g_states[9][256] =
{
	{
		/* 0: default state types */
		PF_SPECIFIER('a') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('A') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('b') = PF_VALUE(PF_UINT32),
		PF_SPECIFIER('B') = PF_VALUE(PF_UINT32),		
		PF_SPECIFIER('c') = PF_VALUE(PF_INT8),
		PF_SPECIFIER('C') = PF_VALUE(PF_INT32),
		PF_SPECIFIER('d') = PF_VALUE(PF_INT32),
		PF_SPECIFIER('D') = PF_VALUE(PF_INT64),
		PF_SPECIFIER('e') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('E') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('f') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('F') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('g') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('G') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('i') = PF_VALUE(PF_INT32),
		PF_SPECIFIER('k') = PF_VALUE(PF_DATE),
		PF_SPECIFIER('m') = PF_VALUE(PF_NO_ARG),
		PF_SPECIFIER('n') = PF_VALUE(PF_PTR),
		PF_SPECIFIER('o') = PF_VALUE(PF_UINT32),
		PF_SPECIFIER('O') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('p') = PF_VALUE(PF_UINTPTR),
		PF_SPECIFIER('r') = PF_VALUE(PF_UINT16),
		PF_SPECIFIER('R') = PF_VALUE(PF_UINT16),
		PF_SPECIFIER('s') = PF_VALUE(PF_PTR),
		PF_SPECIFIER('S') = PF_VALUE(PF_PTR),
		PF_SPECIFIER('u') = PF_VALUE(PF_UINT32),
		PF_SPECIFIER('U') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('x') = PF_VALUE(PF_UINT32),
		PF_SPECIFIER('X') = PF_VALUE(PF_UINT32),
		PF_LENGTH('h') = PF_VALUE(PF_h),
		PF_LENGTH('l') = PF_VALUE(PF_l),
		PF_LENGTH('L') = PF_VALUE(PF_L),
		PF_LENGTH('z') = PF_VALUE(PF_z),
		PF_LENGTH('j') = PF_VALUE(PF_j),
		PF_LENGTH('t') = PF_VALUE(PF_t),
	},
	{
		/* 1: l-prefixed */
		PF_SPECIFIER('a') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('b') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('B') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('c') = PF_VALUE(PF_INT32),
		PF_SPECIFIER('C') = PF_VALUE(PF_INT32),
		PF_SPECIFIER('d') = PF_VALUE(PF_INT64),
		PF_SPECIFIER('D') = PF_VALUE(PF_INT64),
		PF_SPECIFIER('e') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('E') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('f') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('F') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('g') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('G') = PF_VALUE(PF_DOUBLE),
		PF_SPECIFIER('i') = PF_VALUE(PF_INT64),
		PF_SPECIFIER('o') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('O') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('p') = PF_VALUE(PF_UINTPTR),
		PF_SPECIFIER('s') = PF_VALUE(PF_PTR),
		PF_SPECIFIER('u') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('U') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('x') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('X') = PF_VALUE(PF_UINT64),
		PF_LENGTH('l') = PF_VALUE(PF_ll),
		PF_LENGTH('h') = PF_VALUE(PF_l),
		PF_LENGTH('z') = PF_VALUE(PF_l),
	},
	{
		/* 2: ll-prefixed */
		PF_SPECIFIER('d') = PF_VALUE(PF_INT64),
		PF_SPECIFIER('D') = PF_VALUE(PF_INT64),
		PF_SPECIFIER('i') = PF_VALUE(PF_INT64),
		PF_SPECIFIER('o') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('O') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('u') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('U') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('x') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('X') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('n') = PF_VALUE(PF_PTR),
		PF_SPECIFIER('#') = PF_VALUE(PF_ll),
	},
	{
		/* 3: h-prefixed */
		PF_SPECIFIER('d') = PF_VALUE(PF_INT16),
		PF_SPECIFIER('D') = PF_VALUE(PF_INT32),
		PF_SPECIFIER('i') = PF_VALUE(PF_INT16),
		PF_SPECIFIER('o') = PF_VALUE(PF_UINT16),
		PF_SPECIFIER('O') = PF_VALUE(PF_UINT32),
		PF_SPECIFIER('u') = PF_VALUE(PF_UINT16),
		PF_SPECIFIER('U') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('x') = PF_VALUE(PF_UINT16),
		PF_SPECIFIER('X') = PF_VALUE(PF_UINT32),
		PF_SPECIFIER('n') = PF_VALUE(PF_PTR),
		PF_LENGTH('h') = PF_VALUE(PF_hh),
	},
	{
		/* 4: hh-prefixed */
		PF_SPECIFIER('d') = PF_VALUE(PF_INT8),
		PF_SPECIFIER('D') = PF_VALUE(PF_INT32),
		PF_SPECIFIER('C') = PF_VALUE(PF_PTR),
		PF_SPECIFIER('S') = PF_VALUE(PF_PTR),
		PF_SPECIFIER('i') = PF_VALUE(PF_INT8),
		PF_SPECIFIER('o') = PF_VALUE(PF_UINT8),
		PF_SPECIFIER('O') = PF_VALUE(PF_UINT32),
		PF_SPECIFIER('u') = PF_VALUE(PF_UINT8),
		PF_SPECIFIER('U') = PF_VALUE(PF_UINT32),
		PF_SPECIFIER('x') = PF_VALUE(PF_UINT8),
		PF_SPECIFIER('X') = PF_VALUE(PF_UINT8),
		PF_SPECIFIER('n') = PF_VALUE(PF_PTR),
		PF_LENGTH('l') = PF_VALUE(PF_l),
	},
	{
		/* 5: L-prefixed */
		PF_SPECIFIER('d') = PF_VALUE(PF_INT16),
		PF_SPECIFIER('D') = PF_VALUE(PF_INT16),
		PF_SPECIFIER('i') = PF_VALUE(PF_INT16),
		PF_SPECIFIER('o') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('O') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('u') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('U') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('x') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('X') = PF_VALUE(PF_UINT64),
		PF_SPECIFIER('e') = PF_VALUE(PF_LDOUBLE),
		PF_SPECIFIER('f') = PF_VALUE(PF_LDOUBLE),
		PF_SPECIFIER('g') = PF_VALUE(PF_LDOUBLE),
		PF_SPECIFIER('a') = PF_VALUE(PF_LDOUBLE),
		PF_SPECIFIER('E') = PF_VALUE(PF_LDOUBLE),
		PF_SPECIFIER('F') = PF_VALUE(PF_LDOUBLE),
		PF_SPECIFIER('G') = PF_VALUE(PF_LDOUBLE),
		PF_SPECIFIER('A') = PF_VALUE(PF_LDOUBLE),
		PF_SPECIFIER('n') = PF_VALUE(PF_PTR),
	},
	{
		/* 6: z-prefixed */
		PF_SPECIFIER('d') = PF_VALUE(PF_PTRDIFF),
		PF_SPECIFIER('D') = PF_VALUE(PF_PTRDIFF),
		PF_SPECIFIER('i') = PF_VALUE(PF_PTRDIFF),
		PF_SPECIFIER('o') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('O') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('u') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('U') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('x') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('X') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('n') = PF_VALUE(PF_PTR),
		PF_LENGTH('h') = PF_VALUE(PF_z),
	},
	{
		/* 7: t-prefixed */
		PF_SPECIFIER('c') = PF_VALUE(PF_PTRDIFF),
		PF_SPECIFIER('d') = PF_VALUE(PF_PTRDIFF),
		PF_SPECIFIER('D') = PF_VALUE(PF_PTRDIFF),
		PF_SPECIFIER('i') = PF_VALUE(PF_PTRDIFF),
		PF_SPECIFIER('o') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('O') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('u') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('U') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('x') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('X') = PF_VALUE(PF_SIZET),
		PF_SPECIFIER('n') = PF_VALUE(PF_PTR),
	},
	{
		/* 8: j-prefixed */
		PF_SPECIFIER('d') = PF_VALUE(PF_INTMAX),
		PF_SPECIFIER('i') = PF_VALUE(PF_INTMAX),
		PF_SPECIFIER('o') = PF_VALUE(PF_UINTMAX),
		PF_SPECIFIER('u') = PF_VALUE(PF_UINTMAX),
		PF_SPECIFIER('x') = PF_VALUE(PF_UINTMAX),
		PF_SPECIFIER('X') = PF_VALUE(PF_UINTMAX),
		PF_SPECIFIER('n') = PF_VALUE(PF_PTR),
		PF_LENGTH('h') = PF_VALUE(PF_j),
		PF_LENGTH('z') = PF_VALUE(PF_j),
	}
};

static void	ft_pf_setarg(int const type, t_pf_arg *arg, va_list ap)
{
	switch (type)
	{
		case PF_INT8:		arg->i = (int8_t)va_arg(ap, int32_t); break ;
		case PF_UINT8:		arg->i = (uint8_t)va_arg(ap, int32_t); break ;
		case PF_INT16:		arg->i = (int16_t)va_arg(ap, int32_t); break ;
		case PF_UINT16:		arg->i = (uint16_t)va_arg(ap, int32_t); break ;
		case PF_INT32:		arg->i = va_arg(ap, int32_t); break ;
		case PF_UINT32:		arg->i = va_arg(ap, uint32_t); break ;
		case PF_INT64:		arg->i = va_arg(ap, int64_t); break ;
		case PF_UINT64:		arg->i = va_arg(ap, uint64_t); break ;
	    case PF_DATE:		arg->i = va_arg(ap, time_t); break ;
		case PF_SIZET:		arg->i = va_arg(ap, size_t); break ;
		case PF_INTMAX:		arg->i = va_arg(ap, intmax_t); break ;
		case PF_UINTMAX:	arg->i = va_arg(ap, uintmax_t); break ;
		case PF_PTRDIFF:	arg->i = va_arg(ap, ptrdiff_t); break ;
		case PF_UINTPTR:	arg->i = (uintptr_t)va_arg(ap, void *); break ;
		case PF_PTR:		arg->p = va_arg(ap, void *); break ;
		case PF_DOUBLE:		arg->d = va_arg(ap, double); break ;
		case PF_LDOUBLE:	arg->d = va_arg(ap, long double); break ;
		default:			break ;
	}
}

static void	ft_pf_getarg_setup(t_printf *pf, int const specifier)
{
	if (pf->flags & PF_FLAG_MINUS)
		pf->flags &= ~PF_FLAG_ZERO;
	if (pf->flags & PF_FLAG_PLUS)
		pf->flags &= ~PF_FLAG_SPACE;
	if (0 <= pf->precision && 'c' != specifier && 's' != specifier)
		pf->flags &= ~PF_FLAG_ZERO;
}

int			ft_pf_getarg(char **cursor, t_printf *pf, va_list ap)
{
	int		state;
	int		c;

	state = 0;
	while (42)
	{
		c = **cursor;
		pf->length = state;
		state = g_states[state][c];
		if (0 == state)
			return (EXIT_FAILURE);
		if (state >= PF_NO_ARG)
			break ;
		++(*cursor);
	}
//	printf("ok\n");
	pf->specifier = c;
	ft_pf_setarg(state, &pf->arg, ap);
	ft_pf_getarg_setup(pf, c | 32);
	return (EXIT_SUCCESS);
}
