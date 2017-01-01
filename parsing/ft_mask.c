/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:58:38 by rpagot            #+#    #+#             */
/*   Updated: 2017/01/01 09:20:39 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

static unsigned short		ft_check_if_valid2(unsigned short tetri, int area)
{
	if (tetri == 0xCC00)
	{
		area += 4;
		return (tetri);
	}
	else if (tetri == 0x9C00 || tetri == 0x9880 || tetri == 0x9900
			|| tetri == 0xD800 || tetri == 0x8980)
	{
		area += 6;
		return (tetri >> 1);
	}
	else if (tetri == 0xB800)
	{
		area += 6;
		return (tetri >> 2);
	}
	return (0);
}

unsigned short		ft_check_if_valid(unsigned short tetri, int area)
{
	int				i;

	i = 0;
	while (tetri != 0 && ++i)
		tetri = tetri >> 1;
	tetri = tetri << (16 - i);
	if (tetri == 0xE800 || tetri == 0xE400 || tetri == 0xE200
			|| tetri == 0xC880 || tetri == 0xC440 || tetri == 0x8E00
			|| tetri == 0x8C80 || tetri == 0xC600 || tetri == 0x8C40
			|| tetri == 0x88C0)
	{
		area += 6;
		return (tetri);
	}
	else if (tetri == 0xF000 || tetri == 0x8888)
	{
		area += 8;
		return (tetri);
	}
	return (ft_check_if_valid2(tetri, area));
}
