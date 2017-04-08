/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:49:56 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/08 16:40:30 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static int			ft_test_tetri(t_tetri tetri)
{
	int y;

	y = 0;
	while (y < 3)
	{
		tetri.map++;
		tetri.tetri++;
		if ((*tetri.map & *tetri.tetri) != 0)
			break ;
		*tetri.map = *tetri.map | *tetri.tetri;
		++y;
	}
	if (y != 3)
		return (0);
	return (1);
}

static t_tetri		ft_placetetri(t_tetri tetri)
{
	tetri.x = 0;
	while (tetri.x < 256)
	{
		if ((*tetri.map & *tetri.tetri) == 0)
		{
			*tetri.map = *tetri.map & *tetri.tetri;
			if ((ft_test_tetri(tetri) == 1))
				return (tetri);
			tetri.x = (tetri.x / 16) * 16;
		}
		else
		{
			*tetri.tetri = *tetri.tetri >> 1;
			++tetri.x;
		}
		if (tetri.x % 16 == 0)
			tetri.map++;
	}
	tetri.map = 0;
	return (tetri);
}

int					ft_looptetri(t_tetri tetri)
{
	int n;

	n = 0;
	while (tetri.tetri++)
		ft_placetetri(tetri);
	return (1);
}
