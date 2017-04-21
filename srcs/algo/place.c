/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/21 07:55:45 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

static void			shift_tetriception(t_tetri *tetri)
{
	tetri->tetriception[0] >>= 1;
	tetri->tetriception[1] >>= 1;
	tetri->tetriception[2] >>= 1;
	tetri->tetriception[3] >>= 1;
}

static int			ft_test_tetri(t_tetri *tetri)
{
	int i;
	int y;
	int max;

	i = 1;
	max = *tetri->x / 16;
	y = max + 1;
	while (i < 4)
	{
		if ((tetri->map[y] & tetri->tetriception[i++]) != 0)
			return (0);
		y++;
	}
	y = max;
	i = 0;
	while (y < max + 4)
	{
		tetri->map[y] ^= tetri->tetriception[i++];
		++y;
	}
	*tetri->pos = *tetri->x;
	tetri->pos++;
	return (1);
}

static t_tetri		*ft_placetetri(t_tetri *tetri)
{
	int shift;

	*tetri->x = 0;
	while (*tetri->x < 256)
	{
		if (*tetri->x % 16 == 0)
		{
			ft_split_short(tetri);
			shift = 0;
		}
		if ((tetri->map[*tetri->x / 16] & tetri->tetriception[0]) == 0)
		{
			if ((ft_test_tetri(tetri) == 1))
				return (tetri);
			ft_split_short(tetri);
		}
		// tetri->tetriception[0] = tetri->tetriception[0] >> 1;
		shift_tetriception(tetri);
		shift++;
		if (shift + tetri->bits_count > 16)
			*tetri->x = (*tetri->x / 16) * 17 - 1;
		(*tetri->x)++;
	}
	return (tetri);
}

int					ft_looptetri(t_tetri *tetri)
{
	int n;

	n = 0;
	tetri->tetri -= (tetri->i);
	while (n < tetri->nb)
	{
		// CHECK(COUCOU);
		tetri->i = -1;
		ft_placetetri(tetri);
		if (n == 1)
		{
			// CHECK(TROISTOURDEBOUCLESOMG);
			// ft_display_map(tetri);
			// exit(1);
		}
		tetri->tetri++;
		n++;
	}
	return (1);
}
