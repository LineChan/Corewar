/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 15:29:49 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOG_H
# define FT_LOG_H

# include "ft_printf.h"

/* assign fd to the default file descriptor used by the logger */
void			ft_log_assign(int fd);

/* open or creat a file as default filed descriptor used by the logger */
void			ft_log_open(char const *file_name);

/* log user message  */
int				ft_log(char const *format, ...);

/* close current file descriptor, and set up stdout as default */
void			ft_log_close(void);

#endif
