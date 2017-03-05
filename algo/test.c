/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 03:28:36 by rolemass          #+#    #+#             */
/*   Updated: 2017/03/02 06:31:36 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

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