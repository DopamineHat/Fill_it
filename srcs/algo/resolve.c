/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 03:33:30 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/27 08:29:02 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static int			ft_test_tetri(t_tetri *tetri, int shift, int n)
{
	int i;
	int y;
	int max;

	i = 1;
	max = tetri->x / 16;
	y = max + 1;
	while (i < 4)
		if ((tetri->map[y++] & (tetri->tetriception[i++] >> shift)) != 0)
			return (0);
	y = max;
	i = 0;
	while (y < max + 4)
	{
		tetri->map[y] ^= (tetri->tetriception[i++] >> shift);
		++y;
	}
	tetri->pos[n] = tetri->x;
	return (1);
}

int	ft_place_tetri(t_tetri *tetri, int n, int size)
{
	int	shift;

	shift = 0;

	if (n == tetri->backtrack_count)
		tetri->x = tetri->init_shift;
	else
		tetri->x = 0;
	ft_split_short(tetri, n);
	ft_count_bits(tetri);
	while (tetri->x < size)
	{
		if (tetri->x / 16 > tetri->map_size)
		{
			return (tetri->valid_map = -1);
		}
		if (shift + tetri->bits_count >= tetri->map_size)
		{
			tetri->x = tetri->x / 16 * 16 + 16;
			shift = 0;
		}
		if ((tetri->map[tetri->x / 16] & (tetri->tetriception[0] >> shift)) == 0)
		{
			if (ft_test_tetri(tetri, shift, n) >= 1)
				return (tetri->valid_map);
		}
		shift++;
		tetri->x++;
	}
	return (tetri->valid_map = -1);
}
