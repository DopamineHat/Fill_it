/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 03:33:30 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/25 13:55:49 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static int			ft_test_tetri(t_tetri *tetri, int shift)
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
	*tetri->pos = tetri->x;
	if (shift + tetri->bits_count < tetri->map_size && tetri->x / 16 < tetri->map_size && tetri->valid_map == 0)
	{
		return (tetri->valid_map = 2);
	}
	if (tetri->valid_map == 0 && (shift + tetri->bits_count == tetri->map_size || tetri->x / 16 < tetri->map_size))
		tetri->valid_map = 1;
	return (1);
}

int	ft_place_tetri(t_tetri *tetri, int n)
{
	int	shift;

	shift = 0;

	if (n == tetri->backtrack_count)
		tetri->x = tetri->init_shift;
	ft_split_short(tetri);
	ft_count_bits(tetri);
	while (tetri->x < tetri->area)
	{
		if (tetri->x / 16 == 0)
		{
			shift = 0;
			if (tetri->x / 16 > tetri->map_size)
				return (tetri->valid_map = -1);
		}
		if (shift + tetri->bits_count > tetri->map_size)
		{
			tetri->x = tetri->x / 16 * 16 + 16;
			shift = 0;
		}
		if ((tetri->map[tetri->x / 16] & (tetri->tetriception[0] >> shift)) == 0)
		{
			if (ft_test_tetri(tetri, shift) >= 1)
				return (tetri->valid_map);
		}
		shift++;
		tetri->x++;
	}
	return (tetri->valid_map = -1);
}
