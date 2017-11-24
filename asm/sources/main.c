/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/12 23:37:26 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"
#include "ft_asm.h"

int 		main(int argc, char **argv)
{
	char	*file_content;

	if (2 > argc)
	{
		ft_printf("Usage: \"%s <champion.s> [<champion>]\"\n", argv[0]);
		return (0);
	}
	while (0 != *++argv)
	{
		/* Get the content of the input file */
		file_content = ft_loadfile(*argv);
		if (0 != file_content)
			ft_asm(*argv, file_content);
		ft_strdel(&file_content);
	}
	return (0);
}
