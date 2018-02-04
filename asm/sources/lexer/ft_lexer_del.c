/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 16:00:47 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"
# include "libft.h"

void	ft_lexer_del(t_lexer *lexer)
{
	/* Delete each tokens */
	ft_list_apply(&lexer->token_head, &ft_token_del);
}
