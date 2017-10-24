/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_pc_singleton.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:47:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 18:53:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
 * brief      		Singleton gathering each champion's Program Counter
 */

t_pc			*ft_vm_pc_singleton(void)
{
static t_pc		ptr;

		return (&ptr);
}
