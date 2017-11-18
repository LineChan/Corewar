/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/16 23:39:52 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"
# include "ft_ctype.h"
# include "ft_printf.h"

static t_token	*ft_lex_dir_value(t_location *loc, char const *p)
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
		token = ft_token_new(loc->pc, p - loc->pc, TK_DIRECT, loc);
		token->param_op = T_DIR;
	}
	return (token);
}

t_token			*ft_lex_dir(t_location *loc)
{
	t_token		*token;
	char const	*p;

	token = 0;
	p = loc->pc;
	/* Check for '%' */
	if (DIRECT_CHAR == *p)
	{
		++p;

		/* Check for 'value' */
		token = ft_lex_dir_value(loc, p);
		if (0 == token && LABEL_CHAR == *p)
		{
			/* Value failed, but we matched the ':' char that start the label */
			while (0 != ft_strchr(LABEL_CHARS, *++p))
				continue ;
			token = ft_token_new(loc->pc, p - loc->pc, TK_DIRECT, loc);
			token->param_op = T_DIR | T_LAB;
		}
	}
	return (token);
}
