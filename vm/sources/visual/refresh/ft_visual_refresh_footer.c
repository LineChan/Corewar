/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh_footer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 22:40:53 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include <unistd.h>

static void ft_visual_refresh_footer_push(t_visual_footer *queue, char const *name, int color)
{
    size_t  len;

    len = ft_strlen(name);
    ft_memmove(queue->buf, queue->buf + len, FOOTER_SIZE - len);
    ft_memmove(queue->color, queue->color + len, FOOTER_SIZE - len);
    ft_memcpy(queue->buf + FOOTER_SIZE - len, name, len);
    ft_memset(queue->color + FOOTER_SIZE - len, color, len);
}

void		ft_visual_refresh_footer(t_visual_footer *this, char const *name, int color)
{
    unsigned int    i;

    ft_visual_refresh_footer_push(this, name, color);
    ft_visual_refresh_footer_push(this, "   ", 0);
    i = 0;
    while (i < FOOTER_SIZE)
    {
        wattron(this->win, COLOR_PAIR(this->color[i]) | A_BOLD);
        mvwprintw(this->win, 1, 1 + i, "%c", this->buf[i]);
        wattron(this->win, COLOR_PAIR(this->color[i]) | A_BOLD);
        ++i;
    }
    wrefresh(this->win);
}
