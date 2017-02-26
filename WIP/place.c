/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:40:04 by rpagot            #+#    #+#             */
/*   Updated: 2017/02/26 09:17:11 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

unsigned short	ft_placetetri(unsigned short *prepos, unsigned short *tetri)
{
	int x;

	x = 0;
	while (x < 256)
	{
		if ((*prepos & *tetri) == 0)
		{
			*prepos = *prepos & *tetri;
			x = (x / 16) * 16;
		}
		else
		{
			*tetri = *tetri >> 1;
			++x;
		}
		if (x % 16 == 0)
		{
			tetri++;
			prepos++;
		}
	}
}

