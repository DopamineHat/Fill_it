/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:58:38 by rpagot            #+#    #+#             */
/*   Updated: 2016/12/05 02:58:40 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

unsigned short		check_if_valid(unsigned short tetri)
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
	if (tetri == 61440 || tetri == 59392 || tetri == 58368 || tetri == 57856
			|| tetri == 52224 || tetri == 51328 || tetri == 50240
			|| tetri == 36352 || tetri == 34952 || tetri == 35968
			|| tetri == 50688 || tetri == 35904 || tetri == 35008)
		return (tetri);
	else if (tetri == 39936 || tetri == 39040 || tetri == 39168
			|| tetri == 55296 || tetri == 35200)
		return (tetri >> 1);
	else if (tetri == 47104)
		return (tetri >> 2);
	return (0);
}
