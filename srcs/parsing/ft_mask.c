/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:58:38 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/08 19:14:46 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static unsigned short		ft_check_if_valid2(t_tetri tetri)
{
	if (*tetri.tetri == 0xCC00)
	{
		tetri.area += 4;
		return (*tetri.tetri);
	}
	else if (*tetri.tetri == 0x9C00 || *tetri.tetri == 0x9880
			|| *tetri.tetri == 0x9900 || *tetri.tetri == 0xD800
			|| *tetri.tetri == 0x8980)
	{
		tetri.area += 6;
		return (*tetri.tetri >> 1);
	}
	else if (*tetri.tetri == 0xB800)
	{
		tetri.area += 6;
		return (*tetri.tetri >> 2);
	}
	return (0);
}

unsigned short				ft_check_if_valid(t_tetri tetri)
{
	int				i;

	i = 0;
	while (*tetri.tetri != 0 && ++i)
		*tetri.tetri = *tetri.tetri >> 1;
	*tetri.tetri = *tetri.tetri << (16 - i);
	if (*tetri.tetri == 0xE800 || *tetri.tetri == 0xE400
			|| *tetri.tetri == 0xE200 || *tetri.tetri == 0xC880
			|| *tetri.tetri == 0xC440 || *tetri.tetri == 0x8E00
			|| *tetri.tetri == 0x8C80 || *tetri.tetri == 0xC600
			|| *tetri.tetri == 0x8C40 || *tetri.tetri == 0x88C0)
	{
		tetri.area += 6;
		return (*tetri.tetri);
	}
	else if (*tetri.tetri == 0xF000 || *tetri.tetri == 0x8888)
	{
		tetri.area += 8;
		return (*tetri.tetri);
	}
	return (ft_check_if_valid2(tetri));
}