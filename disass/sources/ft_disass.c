/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 17:24:47 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_printf.h"
#include "endian.h"
#include <unistd.h>

/*
** Read magic number first, make sure it is the same as defined in op.h
** It not, abort the engine.
*/
static int	ft_read_header(t_disass *dsm)
{
	size_t magic_len;

	magic_len = sizeof(dsm->header.magic);
	read(dsm->fd_in, &dsm->header.magic, magic_len);
	dsm->header.magic = ft_endian_convert_uint32(dsm->header.magic); 
	if (COREWAR_EXEC_MAGIC != dsm->header.magic)
	{
		ft_fprintf(ft_stderr, "This is not a champion (wrong magic: ");
		ft_fprintf(ft_stderr, "%#8x instead of ", dsm->header.magic);
		ft_fprintf(ft_stderr, "%d)\n", COREWAR_EXEC_MAGIC);
		return (EXIT_FAILURE);
	}
	read(dsm->fd_in, dsm->header.prog_name, sizeof(t_header) - magic_len);
	dsm->header.prog_size = ft_endian_convert_uint32(dsm->header.prog_size);
	return (EXIT_SUCCESS);
}

void		ft_disass(t_disass *dsm)
{
	t_instr_node	*instruction_list;
	void			*data;
	char			*pc;
	uint32_t		byte_pos;

	if (EXIT_FAILURE == ft_read_header(dsm))
		return ;
	data = ft_memalloc(dsm->header.prog_size);
	read(dsm->fd_in, data, dsm->header.prog_size);
	pc = (char *)data;
	while (dsm->header.prog_size > (byte_pos = (pc - (char *)data)))
	{
		instruction_list = (t_instr_node *)ft_memalloc(sizeof(t_instr_node));
		instruction_list->instr = ft_instruction_get(pc);
		instruction_list->byte_pos = byte_pos;
		ft_list_add_tail(&instruction_list->list, &dsm->instr_head);
		pc += instruction_list->instr->instr_size;
	}
	ft_memdel(&data);
}
