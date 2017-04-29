/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/29 03:28:44 by rolemass         ###   ########.fr       */
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
	ft_split_short(tetri, i);
	tetri->map[x] ^= tetri->tetriception[0] >> y;
	tetri->map[x + 1] ^= tetri->tetriception[1] >> y;
	tetri->map[x + 2] ^= tetri->tetriception[2] >> y;
	tetri->map[x + 3] ^= tetri->tetriception[3] >> y;

}

static int			ft_test_each_tetri_soft(t_tetri *tetri, int size)
{
	int i;

	i = 0;
	CHECK(SOFT_TEST_START);
	while (i < tetri->nb)
	{
		tetri->x = 0;
		ft_split_short(tetri, i);
		ft_count_bits(tetri);
		if (ft_place_tetri(tetri, i, size, 0) == -1)
		{
			CHECK(SOFT_TEST_FAIL);
			return (-1);
		}
		i++;
	}
	return (0);
}

static int ft_rec_test_hard(t_tetri *tetri, int i, size_t size, size_t x)
{
	size_t count;

	count = 1;
	if (i >= tetri->nb)
		return (0);
	if (i < 0)
		return (-1);
	tetri->x = (x == 0) ? 0 : x / 16;
	// printf("i = %d\n", i);
	ft_split_short(tetri, i);
	ft_count_bits(tetri);
	if (tetri->pos[i] + x >= size || ft_place_tetri(tetri, i, size, x) == -1)
	{

		if (i - 1 < 0 && tetri->pos[i] + x > size)
			return (-1);
		if (i - 1 < 0)
			return (ft_rec_test_hard(tetri, i, size, tetri->pos[i] + 1));
		ft_unmap_tetri(tetri, i - 1);
		while (i - 1 > 0 && count + tetri->pos[i - 1] < size
			&& ft_rec_test_hard(tetri, i - 1, size, tetri->pos[i - 1] + count) == -1)
		{
			ft_unmap_tetri(tetri, i - 1);
			count++;
		}
	}
	else
		return (ft_rec_test_hard(tetri, i + 1, size, 0));
	if (i >= tetri->nb)
		return (0);
	return (-1);
}


int					ft_looptetri(t_tetri *tetri)
{
	int size;

	tetri->tetri -= (tetri->nb);
	while (1)
	{
		size = tetri->map_size * 16;
		printf("map_size %d\n", tetri->map_size);
		tetri->backtrack_count = tetri->nb - 2;
		if (ft_test_each_tetri_soft(tetri, size) == 0)
			return (size);
		rinit_map(tetri);
		if (ft_rec_test_hard(tetri, 0, size, 0) == 0)
		{
			CHECK(RESOLVE_HARD);
			return (size);
		}
		tetri->map_size++;
	}
	return (-1);
}
