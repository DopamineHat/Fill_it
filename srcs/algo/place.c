/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/23 08:44:18 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>



static int			ft_test_tetri(t_tetri *tetri, int shift)
{
	int i;
	int y;
	int max;

	i = 1;
	max = *tetri->x / 16;
	y = max + 1;
	while (i < 4)
	{
		if ((tetri->map[y] & (tetri->tetriception[i++] >> shift)) != 0)
		{
			// printf("fail at y = %d\n", y);
			return (0);
		}
		y++;
	}
	y = max;
	i = 0;
	while (y < max + 4)
	{
		tetri->map[y] ^= (tetri->tetriception[i++] >> shift);
		++y;
	}
	*tetri->pos = *tetri->x;
	return (1);
}

static int		ft_placetetri(t_tetri *tetri, int keep_x)
{
	int shift;
	// int test = 0;
	int line_max;

	if (keep_x == tetri->backtrack_count)
		*tetri->x = tetri->init_shift;
	line_max = ft_sqrt(tetri->area);
	ft_split_short(tetri);
	ft_count_bits(tetri);
	while (*tetri->x < tetri->area)
	{
		if (*tetri->x % 16 == 0)
		{
			// if (*tetri->x / 16 > tetri->map_size)
			// 	return (1);
			shift = 0;
		}
		if (shift + tetri->bits_count > 16 
			|| (*tetri->x % 16 + tetri->bits_count) > line_max)
		{
			*tetri->x = *tetri->x / 16 * 16 + 16;
			// CHECK(X NEXT LINE?);
			shift = 0;
		}
		if ((tetri->map[*tetri->x / 16] & (tetri->tetriception[0] >> shift)) == 0)
		{
			// printf("*tetri->x: %d\n", *tetri->x);
			// printf("shift before: %d\n", shift);
			if ((ft_test_tetri(tetri, shift) == 1))
				return (0);
		}
		// if (*tetri->x == 5)
		// {
		// 	printf("*tetri->x fail: %d\n", *tetri->x);
		// 	printf("tetriception reset NB: %d\n ligne x: %d\n", test, *tetri->x / 16);
		// 	CHECK(CMP TETRILINE[0] et TETRI MAP x)
		// 	ft_print_tetri(tetri->map[*tetri->x / 16], 0);
		// 	CHECK(TETRICEPTION:)
		// 	ft_print_tetri(tetri->tetriception[0], 0);
		// 	// exit(1);
		// }
		shift++;
		(*tetri->x)++;
		// printf("bit count: %d\n", tetri->bits_count);
	}
	
	// ft_display_map(tetri);
	// CHECK(ERROR);
	// printf("line_max: %d\n", line_max);
	return (1);
}

static int			ft_check_pretetri_pos(t_tetri *tetri, int n)
{
	int i;

	i = 0;
	tetri->pos -= n;
	tetri->tetri -=n;
	while (i < n)
	{
		if (*tetri->pos == -1)
			ft_placetetri(tetri, 0);
		if (*tetri->pos == -1)
			return (1);
		tetri->pos++;
		tetri->tetri++;
		i++;
	}
	return (0);
}

int					ft_looptetri(t_tetri *tetri)
{
	int n;
	int valid_map;

	n = 0;
	valid_map = 0;
	tetri->tetri -= (tetri->nb);
	*tetri->x = 0;
	while (1)
	{
		if (n > tetri->nb)
		{
			if (ft_backtrack(tetri, valid_map) == 1)
				return (0);
			n = tetri->backtrack_count;
			ft_placetetri(tetri, n);
			n++;
		}
		if (tetri->init_shift > 0)
			valid_map = ft_check_pretetri_pos(tetri, n); // verifier si il y a des pieces non posees avant de prendre best_pos
		else if(ft_placetetri(tetri, n) == 1)
		{
			// while (*(tetri->tetri + 1) == *tetri->tetri)
			// 	tetri->tetri++; // double inc pb
			*tetri->pos = -1;
		}
		*tetri->x = 0;
		tetri->tetri++;
		tetri->pos++;
		n++;
	}
	return (1);
}
