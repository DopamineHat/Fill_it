/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 03:33:30 by rolemass          #+#    #+#             */
/*   Updated: 2017/05/10 13:30:40 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

int			ft_test_tetri(t_tetri *tetri, int i, int x)
{
	int shift;
	int y;

	shift = (x == 0) ? 0 : (x % 16);
	y = (x == 0) ? 0 : (x / 16);
	if ((tetri->map[y] & (tetri->block[i].line1 >> shift)) != 0
	|| (tetri->map[y + 1] & (tetri->block[i].line2 >> shift)) != 0
	|| (tetri->map[y + 2] & (tetri->block[i].line3 >> shift)) != 0
	|| (tetri->map[y + 3] & (tetri->block[i].line4 >> shift)) != 0)
		return (-1);
	if ((tetri->block[i].line4 != 0 && y + 3 >= tetri->map_size)
	|| (tetri->block[i].line3 != 0 && y + 2 >= tetri->map_size)
	|| (tetri->block[i].line2 != 0 && y + 1 >= tetri->map_size))
		return (-1);
	tetri->map[y] ^= (tetri->block[i].line1 >> shift);
	tetri->map[y + 1] ^= (tetri->block[i].line2 >> shift);
	tetri->map[y + 2] ^= (tetri->block[i].line3 >> shift);
	tetri->map[y + 3] ^= (tetri->block[i].line4 >> shift);
	tetri->pos[i] = x;
	return (0);
}
