/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:40:04 by rpagot            #+#    #+#             */
/*   Updated: 2017/03/15 04:38:53 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

static int	ft_test_tetri(struct s_tetri t_tetri)
{
	int y;

	y = 0;
	while(y < 3)
	{
		t_tetri.map++;
		t_tetri.tetri++;
		if ((*t_tetri.map & *t_tetri.tetri) != 0)
			break;
		*t_tetri.map = *t_tetri.map ^ *t_tetri.tetri; // seb : "Presque intelligent" 
		++y;
	}
	if (y != 3)
		return (0);
	return (1);
}




unsigned short	*ft_placetetri(struct s_tetri t_tetri)
{
	t_tetri.x = 0;
	while (t_tetri.x < 256)
	{
		if ((*t_tetri.map & *t_tetri.tetri) == 0)
		{
			*t_tetri.map = *t_tetri.map & *t_tetri.tetri;
			if ((ft_test_tetri(t_tetri) == 1))
				return (t_tetri.map);
			t_tetri.x = (t_tetri.x / 16) * 16;
		}
		else
		{
			*t_tetri.tetri = *t_tetri.tetri >> 1;
			++t_tetri.x;
		}
		if (t_tetri.x % 16 == 0)
			t_tetri.map++;
	}
	return (0);
}
