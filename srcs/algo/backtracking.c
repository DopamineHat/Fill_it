/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 02:17:54 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/23 08:34:18 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static void	rinit_map(t_tetri *tetri, int valid_map)
{
	int i;
	int size_max;

	i = 0;
	size_max = tetri->map_size;// Peux s'opti en faisant en fonction de tetri->map_size?
	while (size_max > 0)
	{
		if (valid_map == 0 && tetri->map[size_max] == 0)
		{
			while (i < tetri->nb)
			{
				tetri->best_pos[i] = tetri->pos[i];
				printf("bestpos: %d\n", tetri->best_pos[i]);
				printf("pos: %d\n", tetri->pos[i]);
				i++;
			}
			i = 0;
			while (size_max < tetri->map_size && tetri->map[size_max - i] == 0)
				i++;
			tetri->map_size = size_max - 1;
		}
		tetri->map[size_max] = 0;
		size_max--;
	}
}

int	ft_backtrack(t_tetri *tetri, int valid_map)
{
	tetri->backtrack_count++;
	rinit_map(tetri, valid_map);
	tetri->tetri -= tetri->nb + 1;
	tetri->pos -= tetri->nb + 1;
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
