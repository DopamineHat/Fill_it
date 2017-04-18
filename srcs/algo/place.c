/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/18 11:59:12 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

static int			ft_test_tetri(t_tetri *tetri)
{
	int y;

	y = 0;
	ft_split_short(tetri);
	while (y < 3)
	{
		CHECK(ENTERED_TEST_TETRI_WHILE);
		printf("tetriception :%d\n", tetri->tetriception[y]);
		if ((tetri->map[y] & tetri->tetriception[y]) != 0)
			break ;
		tetri->map[y] = tetri->map[y] ^= tetri->tetriception[y];
		++y;
	}
	ft_display(tetri);
	if (y != 3)
		return (0);
	return (1);
}

static t_tetri		*ft_placetetri(t_tetri *tetri)
{
	printf("this is tetri->sparta :%d\n", *(tetri->tetri));
	*tetri->x = 0;
	// exit(EXIT_FAILURE);
	while (*tetri->x < 256)
	{
		if ((tetri->map[0] & *tetri->tetri) == 0)
		{
			CHECK(TETRI_MAP_UPDATE);
			printf("tetrimap: %d\n", tetri->map[0]);
			if ((ft_test_tetri(tetri) == 1))
				return (tetri);
			printf("tetrimap: %d\n", tetri->map[0]);
			*tetri->x = (*tetri->x / 16) * 16;
		}
		else
		{
			// CHECK(XDDDDD);
			*tetri->tetri = *tetri->tetri >> 1;
			++tetri->x;
		}
		if (*tetri->x % 16 == 0)
			tetri->i++;
	}
	return (tetri);
}

int					ft_looptetri(t_tetri *tetri)
{
	int n;

	n = 0;
	CHECK(THINKING);
	printf("%d\n", tetri->i);
	printf("wait%d\n", *(tetri->tetri-=(tetri->i - 1)));
	tetri->tetri-=(tetri->i - 1);
	CHECK(ENTER_LOOPTETRI);
	printf("tetri->tetri-tetri->i: %d\n", *(tetri->tetri-tetri->i));
	while (*(tetri->tetri) != 0)
	{
		CHECK(COUCOU);
		tetri->i = 0;
		ft_placetetri(tetri);
		printf("%d\n", tetri->i);
		printf("%d\n", *tetri->tetri);
		tetri->tetri++;
	}
	return (1);
}
