/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_relocate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/13 17:41:07 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

void	ft_lexer_relocate(t_location *loc, size_t count)
{
	while (0 != count)
	{
		if ('\n' == loc->pc[0])
		{
			++loc->line;
			loc->pos = 1;
		}
		else
			++loc->pos;
		++loc->pc;
		--count;
	}
}
