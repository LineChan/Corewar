/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/16 23:39:00 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"
# include "ft_ctype.h"
# include "op.h"
# include "ft_printf.h"

t_token		*ft_lex_reg(t_location *loc)
{
	t_token		*token;
	char const	*p;
	int			reg;

	token = 0;
	p = loc->pc;
	/* Register have to start with the 'r' charß
		Sadly, the 'r' token is not defined in op.h */
	if ('r' == *p)
	{
		++p;
		/* Need at least one digit */
		if (0 != ft_isdigit(*p))
		{
			reg = 0;
			while (0 != ft_isdigit(*p))
				reg = (reg << 3) + (reg << 1) + (*p++ - '0');
			/* We need to check if the value is greater than
			 	REG_NUMBER nor equal 0 */
			if (0 == reg || REG_NUMBER < reg)
				return (0);
			token = ft_token_new(loc->pc, p - loc->pc, TK_REGISTER, loc);
			token->param_op = T_REG;
		}
	}
	return (token);
}
