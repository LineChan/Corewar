/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/17 20:42:32 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "ft_parser.h"
# include "ft_asm.h"

extern t_op		g_op_tab[17];

static int		ft_parse_instruction_separator(t_lexer *lexer)
{
	t_token *token;

	token = ft_lexer_read(lexer);
	if (0 == token || TK_SEPARATOR != token->kind)
	{
		ft_error(&lexer->loc, token, "Separator is missing\n");
		return (1);
	}
	return (0);
}

static char		**ft_parse_instruction_init(t_lexer *lexer, t_token *instr)
{
	static char	*tab[4];
	t_token		*token;
	t_op		*op;
	int			i;

	op = &g_op_tab[instr->param_op];
	/* tab[0]    = instruction name;
	   tab[1..N] = instruction arguments. */
/*	tab = ft_memalloc((1 + op->nb_args) * sizeof(char *)); */
	tab[0] = instr->data->str;
	
	/* Loop over expected arguments from op.h */
	i = 0;
	while (i < op->nb_args)
	{
		/* If this is not the first arguments of the instruction,
		 	we expect a ',' separator token */
		if (0 != i && 0 != ft_parse_instruction_separator(lexer))
			return (0);

		/* Get the next token, It have to match op.h arguments type
			corresponding to our current instruction */
		token = ft_lexer_read(lexer);
		if (0 == token || 0 == (op->arg_types[i] & token->kind))
		{
			ft_error(&lexer->loc, token, "Argument is invalide\n");
			return (0);
		}

		/* We accept the argument. Remember tab[0] is
			used for the instruction name */
		tab[++i] = token->data->str;
	}

	/* An instruction can end with an ENDLINE token, or with the end of file */
	token = ft_lexer_read(lexer);
	if (0 != token && TK_ENDLINE != token->kind)
	{
		ft_error(&lexer->loc, instr, "Endline separator is missing\n");
		return (0);
	}

	/* The 2D char array is correct for the instruction parsed. */
	return (tab);
}

t_statement		*ft_parse_instruction(t_lexer *lexer, t_token *token)
{
	t_instr		*instr;
	char		**tab;
	t_statement	*st;
	int			i;
	t_list		*it;

	st = 0;
	/* Create a 2D char array from instruction name and arguments. */
	tab = ft_parse_instruction_init(lexer, token);
	if (0 == tab)
		return (0);
	/* Encode instruction from tab */
	instr = ft_instruction_encode(g_op_tab[token->param_op].nb_args, tab);
	if (0 != instr)
	{
		st = (t_statement *)ft_memalloc(sizeof(t_statement));
		st->instr = instr;

		/* Add tokens corresponding to arguments,
		   mostly used for error printing */
		i = 0;
		it = token->list.next;
		while (i < st->instr->op->nb_args)
		{
			st->token[i] = C_TOKEN(it);
			/* Skip separator */
			it = it->next->next;
			++i;
		}
	}
	return (st);
}
