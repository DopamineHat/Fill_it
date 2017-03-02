/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 03:28:36 by rolemass          #+#    #+#             */
/*   Updated: 2017/03/02 05:07:11 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

unsigned short	*ft_algo(t_tetri tetri, int size)
{
	unsigned short tab[size];
	int x;
	int y;

	tab = init_tab(size);
	x = 0;
	y = 0;
	while (1)
	{

	}
}


t_map		*ft_algro_recursif(t_tetri *tetri, t_map *map)
{
	unsigned short *tmp;

	if (!(*tetri++))
	{
		note_map_density(map);
		reset_map(tetri, map);
		ft_algro_recursif(tetri, map);
	}
	if (y > map->size)
	{
		del_last_tetri(*tetri, t_map *map);
		*tetri++;
	}
	if (*tetri.x < 0 && test_tetri(*tetri, map))
		return (ft_algro_recursif(tetri, map));
	else

}