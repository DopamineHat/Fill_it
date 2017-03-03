/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:40:04 by rpagot            #+#    #+#             */
/*   Updated: 2017/03/03 04:41:53 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

static int	ft_testetri(unsigned short *prepos, unsigned short *tetri, int x)
{
	int y;

	y = 0;
	while(y < 3)
	{
		prepos++;
		tetri++;
		if ((*prepos & *tetri) != 0)
			break;
		*prepos = *prepos & *tetri;
		++y;
	}
	if (y != 3)
		return (0);
	return (1);
}




unsigned short	*ft_placetetri(unsigned short *prepos, unsigned short *tetri)
{
	int x;

	x = 0;
	while (x < 256)
	{
		if ((*prepos & *tetri) == 0)
		{
			*prepos = *prepos & *tetri;
			if ((ft_testetri(prepos, tetri, x) == 1))
				return (prepos);
			x = (x / 16) * 16;
		}
		else
		{
			*tetri = *tetri >> 1;
			++x;
		}
		if (x % 16 == 0)
			prepos++;
	}
	return (0);
}
