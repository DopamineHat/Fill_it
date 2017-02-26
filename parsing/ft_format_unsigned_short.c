/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned_short.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:40:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/02/26 03:57:25 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

t_tetri	*ft_format_unsigned_short(t_tetri new, unsigned short tetri)
{
	new.l[0] = tetri >> 12;
	new.l[0] = new.l[0] << 12;
	new.l[1] = tetri >> 8;
	new.l[1] = new.l[1] << 12;
	new.l[2] = tetri >> 4;
	new.l[2] = new.l[2]<< 12;
	new.l[3] = tetri << 12;
	return (new);
}
