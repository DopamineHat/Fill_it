/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 03:33:30 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/29 06:35:51 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static int			ft_test_tetri(t_tetri *restrict tetri, int shift, int n, int x)
{
	int i;
	int y;

	i = 1;
	y = tetri->x + 1;
	while (i < 4)
	{
		if ((tetri->map[y++] & (tetri->tetriception[i] >> shift)) != 0
			|| (tetri->tetriception[i] != 0 && tetri->x + i >= tetri->map_size))
			return (0);
		i++;
	}
	y = tetri->x;
	i = 0;
	while (y < tetri->x + 4)
	{
		tetri->map[y] ^= (tetri->tetriception[i++] >> shift);
		++y;
	}
	tetri->pos[n] = x;
	return (1);
}

int	ft_place_tetri(t_tetri *tetri, int n, size_t size, size_t x)
{
	int y;

	y = (x == 0) ? (0) : (x % 16);
	// if (x == 0)
	// 	y = 0;
	// else
	// 	y = x % 16;
	while (x < size)
	{
		if (y + tetri->bits_count >= tetri->map_size)
		{
			tetri->x++;
			x = tetri->x * 16;
			y = 0;
		}
		if ((tetri->map[tetri->x] & (tetri->tetriception[0] >> y)) == 0)
		{
			if (ft_test_tetri(tetri, y, n, x) >= 1)
				return (x);
		}
		y++;
		x++;
	}
	return (-1);
}
