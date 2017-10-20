/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 02:57:28 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/02 17:19:58 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNT_SIZE (1 << 7)

/*
** Standard Libraries
*/

# include <fcntl.h>

char			*ft_gnt(const int fd, const char token);
char			*ft_fgnt(const char *line, const char token);

#endif
