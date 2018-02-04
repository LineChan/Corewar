/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/07 13:16:29 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LABEL_H
# define FT_LABEL_H

# include "ft_string.h"
# include "ft_list.h"

typedef struct			s_label
{
	int					address;
	t_string			*data;
	t_list				list;
}						t_label;

#define C_LABEL(it)		CONTAINEROF(it, t_label, list)

#endif
