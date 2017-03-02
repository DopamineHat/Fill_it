/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned_short.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:40:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/03/02 03:09:52 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

t_tetri	ft_format_unsigned_short(t_tetri to_split, unsigned short tetri)
{
	to_split.l[0] = tetri >> 12;
	to_split.l[0] = to_split.l[0] << 12;
	to_split.l[1] = tetri >> 8;
	to_split.l[1] = to_split.l[1] << 12;
	to_split.l[2] = tetri >> 4;
	to_split.l[2] = to_split.l[2]<< 12;
	to_split.l[3] = tetri << 12;
	return (to_split);
}
