/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 03:33:30 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/30 14:44:04 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static int			ft_test_tetri(t_tetri *restrict tetri, int shift, int i, int x)
{
	if ((tetri->block[i].line4 != 0 && tetri->x + 3 >= tetri->map_size)
	|| (tetri->block[i].line3 != 0 && tetri->x + 2 >= tetri->map_size)
 	|| (tetri->block[i].line2 != 0 && tetri->x + 1 >= tetri->map_size))
		return (-1);
	if ((tetri->map[tetri->x + 1] & (tetri->block[i].line2 >> shift)) != 0
		|| (tetri->map[tetri->x + 2] & (tetri->block[i].line3 >> shift)) != 0
		|| (tetri->map[tetri->x + 3] & (tetri->block[i].line4 >> shift)) != 0)
		return (-1);
	tetri->map[tetri->x] ^= (tetri->block[i].line1 >> shift);
	tetri->map[tetri->x + 1] ^= (tetri->block[i].line2 >> shift);
	tetri->map[tetri->x + 2] ^= (tetri->block[i].line3 >> shift);
	tetri->map[tetri->x + 3] ^= (tetri->block[i].line4 >> shift);
	tetri->pos[i] = x;
	return (0);
}

int	ft_place_tetri(t_tetri *tetri, int i, size_t size, size_t x)
{
	int y;

	y = (x == 0) ? (0) : (x % 16);
	tetri->x = (x == 0) ? 0 : (x / 16);
	while (x < size)
	{
		if (y + tetri->range[i] >= tetri->map_size)
		{
			tetri->x++;
			x = tetri->x * 16;
			y = 0;
		}
		if ((tetri->map[tetri->x] & (tetri->block[i].line1 >> y)) == 0)
		{
			if (ft_test_tetri(tetri, y, i, x) == 0)
				return (x);
		}
		y++;
		x++;
	}
	return (-1);
}
