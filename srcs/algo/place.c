/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/25 14:09:20 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>


// static int		ft_placetetri(t_tetri *tetri, int keep_x)
// {
// 	int shift;
// 	// int test = 0;

// 	if (keep_x == tetri->backtrack_count)
// 		*tetri->x = tetri->init_shift;
// 	ft_split_short(tetri);
// 	ft_count_bits(tetri);
// 	while (*tetri->x < tetri->area)
// 	{
// 		if (*tetri->x % 16 == 0)
// 		{
// 			// if (*tetri->x / 16 > tetri->map_size)
// 			// 	return (1);
// 			shift = 0;
// 		}
// 		if (shift + tetri->bits_count > map_size
// 			|| (*tetri->x % 16 + tetri->bits_count) > line_max)
// 		{
// 			*tetri->x = *tetri->x / 16 * 16 + 16;
// 			// CHECK(X NEXT LINE?);
// 			shift = 0;
// 		}
// 		if ((tetri->map[*tetri->x / 16] & (tetri->tetriception[0] >> shift)) == 0)
// 		{
// 			// printf("*tetri->x: %d\n", *tetri->x);
// 			// printf("shift before: %d\n", shift);
// 			if ((ft_test_tetri(tetri, shift) == 1))
// 				return (0);
// 		}
// 		shift++;
// 		(*tetri->x)++;
// 		// printf("bit count: %d\n", tetri->bits_count);
// 	}
	
// 	// ft_display_map(tetri);
// 	// CHECK(ERROR);
// 	// printf("line_max: %d\n", line_max);
// 	return (1);
// }

static void			ft_check_pretetri_pos(t_tetri *tetri, int n)
{
	int i;

	i = 0;
	// printf("n = %d\n", n);
	tetri->pos -= n;
	tetri->tetri -= n;
	while (i < n)
	{
		if (*tetri->pos == -1)
			ft_place_tetri(tetri, 0);
		if (*tetri->pos == -1)
			tetri->valid_map = -1;
		tetri->pos++;
		tetri->tetri++;
		i++;
	}
	// if (tetri->valid_map == 1)
	// {
	// 	CHECK(UNVALID MAP)
	// 	exit(1);
	// }

	// printf("valid_map: %d\n", tetri->valid_map);
}

int					ft_looptetri(t_tetri *tetri)
{
	int n;
	int to_check_map_size = 0;

	n = 0;
	tetri->valid_map = 0;
	tetri->tetri -= (tetri->nb);
	tetri->x = 0;
	while (1)
	{
		if (n == tetri->nb)
		{
			if (ft_backtrack(tetri, to_check_map_size) == 1)
				return (0);
			n = 0;
			// ft_place_tetri(tetri, n);
		}
		if (tetri->valid_map == -1)
			ft_check_pretetri_pos(tetri, n); // verifier si il y a des pieces non posees avant de prendre best_pos
		if ((to_check_map_size = ft_place_tetri(tetri, n)) == -1)
		{
			// while (*(tetri->tetri + 1) == *tetri->tetri)
			// 	tetri->tetri++; // double inc pb
			// printf("tetripos add : %p\n", tetri->pos);
			*tetri->pos = -1;
		}
		// if (to_check_map_size == 2)
		// 	CHECK(VALID_MAP);
		tetri->x = 0;
		tetri->tetri++;
		tetri->pos++;
		n++;
	}
	return (1);
}
