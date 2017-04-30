/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/30 14:41:38 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

void ft_unmap_tetri(t_tetri *tetri, int i)
{
	int x;
	int y;

	x = tetri->pos[i] / 16;
	y = tetri->pos[i] % 16;
	tetri->map[x] ^= tetri->block[i].line1 >> y;
	tetri->map[x + 1] ^= tetri->block[i].line2 >> y;
	tetri->map[x + 2] ^= tetri->block[i].line3 >> y;
	tetri->map[x + 3] ^= tetri->block[i].line4 >> y;
	i++;
}

static int			ft_solve_tetri(t_tetri *tetri, int i, size_t size, size_t x)
{
	if (i >= tetri->nb)
		return (0);

	while (1)
	{
		// CHECK(TEST_BY_SIZE);
		if (x + tetri->range[i] > size)
			return (-1);
		if (ft_place_tetri(tetri, i, size, x) == -1)
			return (-1);
		else if (ft_solve_tetri(tetri, i + 1, size, 0) == 0)
		{
			CHECK(YOLO);
			return (0);
		}
			// printf("x = %zu\n", x);
			// printf("i = %d\n", i);
		ft_unmap_tetri(tetri, i);
		x++;
		// ft_place_tetri(tetri, i, size, ++x);
	}
}

int					ft_test_by_size(t_tetri *tetri)
{
	int size;

	// tetri->tetri -= (tetri->nb);
	while (1)
	{
		size = tetri->map_size * 16;
		// if (ft_test_each_tetri_soft(tetri, size) == 0)
		// 	return (size);
		rinit_map(tetri);
		printf("map_size %d\n", tetri->map_size);
		if (ft_solve_tetri(tetri, 0, size, 0) == 0)
		{
			CHECK(RESOLVE_HARD);
			printf("nb = %d\n", tetri->nb);
			return (size);
		}
		// exit(1);
		tetri->map_size++;
	}
	return (-1);
}
