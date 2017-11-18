/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/10 00:14:39 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "ft_parser.h"
# include "ft_label.h"

int			ft_parse_label(t_token *token, int address, t_list *head)
{
	t_list	*it;
	t_label	*label;

	/* Check if label with same name is already defined */
	it = head->next;
	while (it != head)
	{
		label = C_LABEL(it);
		if (0 == ft_strcmp(token->data->str, label->data->str))
			return (0);
		it = it->next;
	}
	/* Add label */
	label = (t_label *)ft_memalloc(sizeof(t_label));
	label->address = address;
	label->data = token->data;
	ft_list_add_tail(&label->list, head);
	return (1);
}
