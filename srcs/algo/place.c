/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/22 06:20:40 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>


// static void			shift_tetriception(t_tetri *tetri)
// {
// 	tetri->tetriception[0] >>= 1;
// 	tetri->tetriception[1] >>= 1;
// 	tetri->tetriception[2] >>= 1;
// 	tetri->tetriception[3] >>= 1;
// }

static int			ft_test_tetri(t_tetri *tetri, int shift)
{
	int i;
	int y;
	int max;

	i = 1;
	max = *tetri->x / 16;
	y = max + 1;
	printf("shift after: %d\n", shift);

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
	// ft_print_tetri(tetri->tetriception[0], 1);
	ft_putchar('\n');
	// ft_print_tetri((tetri->tetriception[0] >> shift), 1);
	ft_putchar('\n');
	while (y < max + 4)
	{
		CHECK (COUCOU);
		tetri->map[y] ^= (tetri->tetriception[i++] >> shift);
		++y;
	}
	*tetri->pos = *tetri->x;
	tetri->pos++;
	return (1);
}

static t_tetri		*ft_placetetri(t_tetri *tetri)
{
	int shift;
	int test = 0;
	int line_max;

	*tetri->x = 0;
	line_max = ft_sqrt(tetri->area);
	ft_split_short(tetri);
	ft_count_bits(tetri);
	while (*tetri->x < tetri->area)
	{
		if (*tetri->x % 16 == 0)
		{
			test++;
			// CHECK(SHIFT_RESET); 
			shift = 0;
		}
		if (shift + tetri->bits_count > 16 
			|| (*tetri->x % 16 + tetri->bits_count) > line_max)
		{
			*tetri->x = *tetri->x / 16 * 16 + 16;
			CHECK(X NEXT LINE?);
			shift = 0;
		}
		if ((tetri->map[*tetri->x / 16] & (tetri->tetriception[0] >> shift)) == 0)
		{
			// printf("*tetri->x: %d\n", *tetri->x);
			// printf("shift before: %d\n", shift);
			if ((ft_test_tetri(tetri, shift) == 1))
				return (tetri);
			// ft_split_short(tetri);
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
		// tetri->tetriception[0] = tetri->tetriception[0] >> 1;
		// shift_tetriception(tetri);
		shift++;
		(*tetri->x)++;
		// printf("bit count: %d\n", tetri->bits_count);
	}
	
	ft_final_display(tetri);
	// ft_display_map(tetri);
	CHECK(ERROR);
	exit(1);
	printf("line_max: %d\n", line_max);
	return (tetri);
}

int					ft_looptetri(t_tetri *tetri)
{
	int n;

	n = 0;
	tetri->tetri -= (tetri->i);
	while (n < tetri->nb)
	{
		// ft_count_bits(tetri);
		// CHECK(COUCOU);
		tetri->i = -1;
		ft_placetetri(tetri);
		if (n == 3)
		{
			// CHECK(TROISTOURDEBOUCLESOMG);
			// // // // ft_print_tetri(*tetri->tetri, 1);
			// exit(1);
		}
		tetri->tetri++;
		n++;
	}
	return (1);
}
