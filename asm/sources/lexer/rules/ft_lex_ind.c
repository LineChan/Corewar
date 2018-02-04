/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_ind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 21:49:57 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_ctype.h"
#include "ft_printf.h"

static t_token	*ft_lex_ind_value(t_location *loc, char const *p)
{
	t_token	*token;

	token = 0;
	/* accept any sign */
	if ('-' == *p || '+' == *p)
		++p;
	/* We need at least one digit to create the token.
	   '%', '%+' or '%-' tokens are not valide. */ 
	if (0 != ft_isdigit(*p++))
	{
		/* Skip digits regardless of int overflow */
		while (0 != ft_isdigit(*p))
			++p;
		token = ft_token_new(loc->pc, p - loc->pc, TK_INDIRECT, loc);
		token->param_op = T_IND;
	}
	return (token);
}

t_token			*ft_lex_ind(t_location *loc)
{
	t_token		*token;
	char const	*p;

	p = loc->pc;
	/* Check for indirect value */
	token = ft_lex_ind_value(loc, p);
	if (0 == token && LABEL_CHAR == *p)
	{
		/* Value failed, but we matched the ':' char that start the label */
		while (0 != ft_strchr(LABEL_CHARS, *++p))
			continue ;
		token = ft_token_new(loc->pc, p - loc->pc, TK_INDIRECT, loc);
		token->param_op = T_IND | T_LAB;
	}
	return (token);
}
