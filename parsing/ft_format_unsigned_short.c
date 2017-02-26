/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned_short.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:40:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/02/26 00:59:52 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

t_tetri	*ft_format_unsigned_short(t_tetri new, unsigned short tetri)
{
	new->l1 = tetri >> 12;
	new->l1 = new->l1 << 12;
	new->l2 = tetri >> 8;
	new->l2 = new->l2 << 12;
	new->l3 = tetri >> 4;
	new->l3 = new->l3 << 12;
	new->l4 = tetri << 12;
	return (new);
}
