/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:42:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/23 00:13:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/**
 * \fn void ft_vm_arena_print(char arena[])
 * \brief Print the arena
 *
 * \param number of arguments
 * \return None
 */

void		ft_vm_arena_print(char arena[])
{
	ft_printf("coucou\n");
	int i;
	int j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = 0;
		while (j < 17)
		{

			ft_fprintf(2, "%02x %02x\n", arena[i], arena[i + 1]);
			i += 2;
			++j;
		}
		j = 0;
		write(2, "\n", 1);
		//ft_fprintf(2, "%x", arena[i]);
		//ft_fprintf(2, "%x \t", arena[i]);
		++i;
	}
	write(2, "\n", 1);
	ft_printf("coucou\n");
}
