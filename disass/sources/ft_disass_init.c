/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/16 21:01:27 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_string.h"
#include "ft_printf.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static int	ft_open_file_in(char const *file)
{
	struct stat	st;
	int			fd;

	/* Check for valide suffix '.cor' */
	if (*(uint32_t *)".cor" != *(uint32_t *)(file + ft_strlen(file) - 4))
	{
		ft_fprintf(ft_stderr, "File {red:%s} is not a champion object\n", file);
		return (-1);
	}
	/* Check if file exist */
	if (0 > stat(file, &st))
	{
		ft_fprintf(ft_stderr, "File {red:%s} does not exist\n", file);
		return (-1);
	}
	/* Check if file is readable */
	fd =  open(file, O_RDONLY);
	if (0 > fd)
		ft_fprintf(ft_stderr, "Can't open file {red:%s}\n", file);
	return (fd);
}

static int	ft_open_file_out(char const *file)
{
	struct stat	st;
	int			fd;

	/* Check for valide suffix '.s' */
	if (*(uint16_t *)".s" != *(uint16_t *)(file + ft_strlen(file) - 2))
	{
		ft_fprintf(ft_stderr, "File {red:%s} is not a champion object\n", file);
		return (-1);
	}
	/* Check if file exist */
	if (0 <= stat(file, &st))
	{
		ft_fprintf(ft_stderr, "File {red:%s} already exist\n", file);
		return (-1);
	}
	/* try if file is readable */
	fd =  open(file, O_WRONLY | O_CREAT, 0644);
	if (0 > fd)
		ft_fprintf(ft_stderr, "Can't create file {red:%s}\n", file);
	return (fd);
}

int			ft_disass_init(t_disass *dsm, char const *file)
{
	t_string	*file_out;

	/* Init lists */
	INIT_LIST_HEAD(dsm->instr_head);
	INIT_LIST_HEAD(dsm->label_head);

	/* open input file */
	dsm->fd_in = ft_open_file_in(file);
	if (0 > dsm->fd_in)
		return (EXIT_FAILURE);

	/* Create output name champion.s */
	file_out = ft_string_ndup(file, ft_strlen(file) - 4);
	ft_string_cat(file_out, ".s");

	/* open output file */
	dsm->fd_out = ft_open_file_out(file_out->str);
	if (0 > dsm->fd_out)
	{
		ft_string_del(&file_out);
		return (EXIT_FAILURE);
	}
	ft_string_del(&file_out);
	return (EXIT_SUCCESS);
}
