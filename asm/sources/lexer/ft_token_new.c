/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/15 19:19:47 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

t_token	*ft_token_new(char const *data, size_t len, int kind, t_location *loc)
{
	t_token	*token;

	token = (t_token *)ft_memalloc(sizeof(t_token));
	token->data = ft_string_ndup(data, len);
	token->kind = kind;
	token->loc = loc[0];
	ft_lexer_relocate(loc, len);
	return (token);
}
