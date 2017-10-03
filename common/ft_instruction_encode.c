/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_encode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/03 21:47:36 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "endian.h"
#include "ft_printf.h"
#include "ft_string.h"
#include "ft_ctype.h"

extern uint8_t	g_direct_jump_table_from_instr[17];

static int32_t	ft_atoi(char const *p)
{
    int32_t x;
    int     neg;

    neg = 0;
    if ('-' == *p)
    {
    	neg = 1;
    	++p;
    }
    else if ('+' == *p)
        ++p;
    x = 0;
    while (0 != ft_isdigit(*p))
        x = (x << 3) + (x << 1) + (*p++ - '0');
    if (1 == neg)
    	x = -x;
    return (x);
}

static int32_t	ft_instruction_encode_arg(t_instr_encode *st, char const *data, int num)
{
	if ('r' == data[0])
	{
		st->type = T_REG;
		st->size = 1;
		ft_endian_apply_conversion((void *)st->data, ft_atoi(data + 1), 1);
		return (T_REG);
	}
	if ('%' != data[0])
	{
		st->type = T_IND;
		st->size = 2;
		ft_endian_apply_conversion((void *)st->data, ft_atoi(data), 2);
		return (T_IND - 1);
	}
	st->type = T_DIR;
	st->size = g_direct_jump_table_from_instr[num];
	if (':' == data[1])
	{
		st->type |= T_LAB;
		ft_strcpy(st->data, data);
	}
	else
		ft_endian_apply_conversion((void *)st->data, ft_atoi(data + 1), st->size);
	return (T_DIR);
}

static uint8_t	ft_instruction_encode_set_args(t_instr *st, int argc, char **tab)
{
	t_instr_encode	*ptr;
	int				num;
	int 			bytecode;

	ptr = st->args.encode;
	num = st->op->numero;
	bytecode = ft_instruction_encode_arg(&ptr[0], tab[0], num) << 6;
	if (1 < st->op->nb_args && 1 < argc)
		bytecode |= ft_instruction_encode_arg(&ptr[1], tab[1], num) << 4;
	if (2 < st->op->nb_args && 2 < argc)
		bytecode |= ft_instruction_encode_arg(&ptr[2], tab[2], num) << 2;
	return (st->op->param_byte * bytecode);
}

t_instr			*ft_instruction_encode(int argc, char **tab)
{
	extern t_op	g_op_tab[17];
	t_instr		*st;
	int			i;

	i = 1;
	while (i < 17 && 0 != ft_strcmp(g_op_tab[i].name, tab[0]))
		++i;
	if (17 == i)
		return (0);
	st = (t_instr *)ft_calloc(1, sizeof(t_instr));
	st->type = INSTR_ENCODE;
	st->op = &g_op_tab[i];
	st->args.encode = (t_instr_encode *)ft_calloc(st->op->nb_args, sizeof(t_instr_encode));
	st->bytecode = ft_instruction_encode_set_args(st, argc - 1, tab + 1);
	return (st);
}
