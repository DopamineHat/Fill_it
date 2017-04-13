/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:49:56 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/13 02:42:38 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

static int			ft_test_tetri(t_tetri tetri)
{
	tetri.tetri+=tetri.i;
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
	// CHECK(NIQUE_TA_MERE);
	tetri.tetri+=tetri.i;
	*tetri.x = 0;
	printf("this is tetri.sparta :%d\n", tetri.i);
	// exit(EXIT_FAILURE);
	while (*tetri.x < 256)
	{
		if ((*tetri.map & *tetri.tetri) == 0)
		{
			// CHECK(NIQUETAMERELAPUTE);
			*tetri.map = *tetri.map | *tetri.tetri;
			printf("%d\n", *tetri.map);
			if ((ft_test_tetri(tetri) == 1))
				return (tetri);
			*tetri.x = (*tetri.x / 16) * 16;
		}
		else
		{
			// CHECK(XDDDDD);
			*tetri.tetri = *tetri.tetri >> 1;
			++tetri.x;
		}
		if (*tetri.x % 16 == 0)
			tetri.map++;
	}
	tetri.map = 0;
	return (tetri);
}

int					ft_looptetri(t_tetri tetri)
{
	int n;

	n = 0;
	// CHECK(NIQUETAMERE);
	while (*tetri.tetri+=tetri.i != 0)
	{
		ft_placetetri(tetri);
		tetri.i++;
	}
	return (1);
}
