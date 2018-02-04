/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 01:16:16 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

void	ft_token_del(t_list *it)
{
	t_token	*token;

	token = C_TOKEN(it);
	ft_string_del(&token->data);
	ft_memdel((void **)&token);
	ft_list_del(it);
}
