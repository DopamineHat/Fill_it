/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/28 00:19:47 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

static int			ft_check_if_done(t_tetri *tetri)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < tetri->nb)
	{
		if (tetri->pos[i] == -1)
			return (-1);
		if (count == 0 && tetri->pos[i] == 0)
			count++;
		if (count > 0 && tetri->pos[i] == 0)
			return (-1);
		i++;
	}
	return (0);
}



static int			ft_test_each_tetri_soft(t_tetri *tetri, int size)
{
	int i;

	i = 0;
	CHECK(SOFT_TEST_START);
	while (i < tetri->nb)
	{
		if (ft_place_tetri(tetri, i, size) == -1)
		{
			CHECK(SOFT_TEST_FAIL);
			return (-1);
		}
		i++;
	}
	return (0);
}

static void			ft_check_pretetri_pos(t_tetri *tetri, int n, int size)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (tetri->pos[i] == -1)
		{
			// CHECK(TRY HARDER);
			ft_place_tetri(tetri, -1, size);
		}
		i++;
	}
}

static int			ft_test_each_tetri_hard(t_tetri *tetri, int size)
{
	int i;
	int test;

	test = 0;
	tetri->valid_map = 0;
	tetri->backtrack_count = tetri->nb - 2;
	CHECK(HARD_TEST);
	while (tetri->backtrack_count >= 0)
	{
		i = 0;
		while (i < tetri->nb)
		{
			if (i > 0 && tetri->valid_map == -1)
				ft_check_pretetri_pos(tetri, i, size);
			if (ft_place_tetri(tetri, i, size) == -1)
				tetri->pos[i] = -1;
			i++;
		}
		test++;
		if (ft_check_if_done(tetri) == 0)
			return (0);
		ft_backtrack(tetri, size);
	}
	return (-1);
}

int					ft_looptetri(t_tetri *tetri)
{
	int size;

	tetri->tetri -= (tetri->nb);
	while (1)
	{
		size = tetri->map_size * 16;
		if (ft_test_each_tetri_soft(tetri, size) == 0)
			return (size);
		rinit_map(tetri);
		tetri->init_shift = 0;
		if (ft_test_each_tetri_hard(tetri, size) == 0)
		{
			CHECK(RESOLVE_HARD);
			return (size);
		}
		tetri->map_size++;
	}
	return (-1);
}
