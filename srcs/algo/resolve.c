/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/05/01 14:11:32 by rolemass         ###   ########.fr       */
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

static int			ft_solve_tetri(t_tetri *tetri, int i, size_t size, int x)
{
	if (i >= tetri->nb)
		return (0);
	// if (i == 8)
	// {
	// 	ft_final_display(tetri);
	// 	exit(1);
	// }
	tetri->x = 0;
	while (1)
	{
		if (x > 0 && (tetri->range[i] - 1) + (x % 16) >= tetri->map_size)
		{
			x = (x / 16) * 16 + 16;
		}
		if ((size_t)(x + tetri->range[i]) >= size)
			return (tetri->pos[i] = -1);
		if (ft_test_tetri(tetri, i, x) == 0)
		{
			if (ft_solve_tetri(tetri, i + 1, size, 0) == 0)
				return (0);
			ft_unmap_tetri(tetri, i);
		}
			// printf("x = %zu\n", x);
		x++;
	}
}

int					ft_test_by_size(t_tetri *tetri)
{
	int size;

	while (1)
	{
		size = tetri->map_size * 16;
		rinit_map(tetri);
		printf("map_size %d\n", tetri->map_size);
		printf("range[0] %d\n", tetri->range[0]);
		if (ft_solve_tetri(tetri, 0, size, 0) == 0)
		{
			CHECK(RESOLVE_HARD);
			printf("nb = %d\n", tetri->nb);
			printf("pos[0] %d\n", tetri->pos[0]);
			return (size);
		}
		// exit(1);
		tetri->map_size++;
	}
	return (-1);
}
