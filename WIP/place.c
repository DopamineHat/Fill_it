/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:40:04 by rpagot            #+#    #+#             */
/*   Updated: 2017/03/15 04:44:37 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

static int	ft_test_tetri(t_tetri tetri)
{
	int y;

	y = 0;
	while(y < 3)
	{
		tetri.map++;
		tetri.tetri++;
		if ((*tetri.map & *tetri.tetri) != 0)
			break;
		*tetri.map = *tetri.map ^ *tetri.tetri; // seb : "Presque intelligent" 
		++y;
	}
	if (y != 3)
		return (0);
	return (1);
}




unsigned short	*ft_placetetri(t_tetri tetri)
{
	tetri.x = 0;
	while (tetri.x < 256)
	{
		if ((*tetri.map & *tetri.tetri) == 0)
		{
			*tetri.map = *tetri.map & *tetri.tetri;
			if ((ft_test_tetri(tetri) == 1))
				return (tetri.map);
			tetri.x = (tetri.x / 16) * 16;
		}
		else
		{
			*tetri.tetri = *tetri.tetri >> 1;
			++tetri.x;
		}
		if (tetri.x % 16 == 0)
			tetri.map++;
	}
	return (0);
}
