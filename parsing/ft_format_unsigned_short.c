/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned_short.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:40:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/02/24 22:07:52 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

t_dlist	*ft_format_unsigned_short(t_dlist *list, unsigned short tetri)
{
	list->l1 = tetri >> 12;
	list->l1 = list->l1 << 12;
	list->l2 = tetri >> 8;
	list->l2 = list->l2 << 12;
	list->l3 = tetri >> 4;
	list->l3 = list->l3 << 12;
	list->l4 = tetri << 12;
	return (list);
}
