/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:58:38 by rpagot            #+#    #+#             */
/*   Updated: 2016/12/31 06:15:07 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

unsigned short		ft_check_if_valid(unsigned short tetri)
{
	unsigned short	tmp;
	int				i;

	i = 0;
	tmp = tetri;
	if (tmp == 0)
		return (0);
	while (tmp != 0 && ++i)
		tmp = tmp >> 1;
	tetri = tetri << (16 - i);
	if (tetri == 0xF000 || tetri == 0xE800 || tetri == 0xE400
			|| tetri == 0xE200 || tetri == 0xCC00 || tetri == 0xC880
			|| tetri == 0xC440 || tetri == 0x8E00 || tetri == 0x8888
			|| tetri == 0x8C80 || tetri == 0xC600 || tetri == 0x8C40
			|| tetri == 0x88C0)
		return (tetri);
	else if (tetri == 0x9C00 || tetri == 0x9880 || tetri == 0x9900
			|| tetri == 0xD800 || tetri == 0x8980)
		return (tetri >> 1);
	else if (tetri == 0xB800)
		return (tetri >> 2);
	return (0);
}
