/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/20 09:12:25 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

static int			ft_test_tetri(t_tetri *tetri, int shift)
{
	int y;

	y = tetri->i - 1;
	// printf("I AM HERE %x", *tetri->tetri);
	while (++y < (tetri->i + 4))
	{
		if (y > 0 && shift > 0)
			tetri->tetriception[y] = tetri->tetriception[y] >> shift;
		if ((tetri->map[y] & tetri->tetriception[y]) != 0)
			return (0);
	}
	y = tetri->i;
	while (y < (tetri->i + 4))
	{
		CHECK(ENTERED_TEST_TETRI_WHILE);
		// printf("tetriception :%d\n", tetri->tetriception[y]);
		tetri->map[y] ^= tetri->tetriception[y]; //wtf?
		++y;
	}
	ft_display(tetri);
	return (1);
}

static t_tetri		*ft_placetetri(t_tetri *tetri)
{
	int shift;

	printf("this is tetri->sparta :%d\n", *(tetri->tetri));
	*tetri->x = 0;
	while (*tetri->x < 256)
	{
		if (*tetri->x % 16 == 0)
		{
			ft_split_short(tetri);
			shift = 0;
			tetri->i++;
		}
		if ((tetri->map[*tetri->x / 16] & tetri->tetriception[0]) == 0)
		{
			CHECK(TETRI_MAP_UPDATE);
			// printf("tetrimap: %x\n", tetri->map[0]);
			if ((ft_test_tetri(tetri, shift) == 1))
				return (tetri);
			// printf("tetrimap: %x\n", tetri->map[0]);
		}
		*tetri->tetri = tetri->tetriception[0] >> 1;
		if (shift + tetri->bits_count > 16)
			*tetri->x = (*tetri->x / 16) * 17 - 1;
		shift++;
		tetri->i = *tetri->x / 16;
		(*tetri->x)++;
		// 	tetri->i++;
	}
	printf("tetri->x: %d\n", *tetri->x);
	return (tetri);
}

int					ft_looptetri(t_tetri *tetri)
{
	int n;

	n = 0;
	printf("%d\n", tetri->i);
	// printf("wait%d\n", *(tetri->tetri-=(tetri->i - 1)));
	tetri->tetri -= (tetri->i);
	CHECK(ENTER_LOOPTETRI);
	// printf("tetri->tetri-tetri->i: %d\n", *(tetri->tetri-tetri->i));
	printf("nb = %d\n", tetri->nb);
	while (n < tetri->nb)
	{
		CHECK(COUCOU);
		tetri->i = -1;
		if (n == 2)
		{
			CHECK(TROISTOURDEBOUCLESOMG);

			// exit(1);
			ft_print_tetri(*tetri->tetri, 1);
			// ft_display(tetri);
			// exit(1);
		}
		ft_placetetri(tetri);
		// if (n == 1)
		// {
		// 	CHECK(TOTO);
		// 	// ft_display_map(tetri);
		// 	// exit(1);
		// }
		tetri->tetri++;
		n++;
	}
	return (1);
}
