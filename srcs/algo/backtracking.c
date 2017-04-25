/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 02:17:54 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/25 14:04:20 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static void	ft_best_pos_update(t_tetri *tetri)
{
	int i;
	int j;
	int size_max;

	i = 0;
	j = 0;
	size_max = tetri->map_size;
	CHECK(best_pos_up);
	while (tetri->map[tetri->map_size - size_max] == 0)
		size_max++;
	while (i < tetri->map_size && tetri->map[i] != 0)
	{
		tetri->map[i] >>= 16 - tetri->map_size;
		while (((tetri->map[i] >> j) & 1) == 0)
			j++;
		if (j < size_max)
			size_max = j;
		i++;
	}
	tetri->map_size -= size_max;
	i = 0;
	while (i < tetri->nb)
	{
		tetri->best_pos[i] = tetri->pos[i];
		printf("bestpos: %d\n", tetri->best_pos[i]);
		i++;
	}
	// ft_final_display(tetri);
}

static void	rinit_map(t_tetri *tetri)
{
	int size_max;

	size_max = ft_sqrt(tetri->area) + 2;
	while (size_max >= 0)
	{
		tetri->map[size_max] = 0;
		size_max--;
	}
	tetri->valid_map = 0;
}

int	ft_backtrack(t_tetri *tetri, int to_check_map_size)
{
	tetri->backtrack_count++;
	tetri->tetri -= tetri->nb;
	tetri->pos -= tetri->nb;
	tetri->x = 0;
	if (to_check_map_size == 2 && tetri->valid_map != -1)
	{
		CHECK(OMG_VALID_MAP);
		ft_best_pos_update(tetri);
	}
	rinit_map(tetri);
	if (tetri->backtrack_count > tetri->nb)
	{
		tetri->init_shift++;
		if (tetri->init_shift > tetri->area)
		{
			CHECK(WE ARE DONE);
			// ft_final_display(tetri);
			// ft_display_map(tetri);
			return (1);
		}
		tetri->backtrack_count = 0;
	}
	return (0);
}
