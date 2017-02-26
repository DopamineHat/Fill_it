/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_final_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 03:21:26 by rolemass          #+#    #+#             */
/*   Updated: 2017/02/26 04:48:55 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

static t_final_map	init_final_map(int size)
{
	t_final_map	pos;
	int			x;
	int			y;

	x = 0;
	pos.x = 0;
	pos.y = 0;
	pos.letter = 'A';
	if (!(pos.final_map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (x < size)
	{
		y = 0
		if (!(pos.final_map[x] = (char*)malloc(sizeof(char) * 16)))
			return (NULL);
		while (y < 16)
			pos.final_map[x][y++] = '.';
		x++;
	}
	return (final_map);
}

void	ft_place_one_final_tetri(t_tetri tetri, t_final_map pos)
{
	int i;
	int count;

	i = 0;
	pos.x = tetri.x % 16;
	pos.y = tetri.x / 16;
	tetri.l[0] = tetri.l[0] << pos.x;
	while (i < 4)
	{
		count = 0;
		while ((tetri[i] = (tetri[i] << 1)) > 0 && count < 4)
		{
			if (tetri[i] > 225)
			{
				pos.final_map[pos.x][pos.y] = pos.letter;
				count++;
			}
			pos.x++;
		}
		pos.x = 0;
		i++;
		pos.y++;
	}
}


char	**ft_format_final_map(t_tetri *tab, t_final_map pos, int size)
{
	t_final_map	pos;
	int			i;

	if (!(pos = init_final_map(size)))
		return (NULL);
	i = 0;
	while (pos.y <= size)
	{
		ft_place_one_final_tetri(tab[i], pos);
		pos.letter++;
		i++;
	}
	return (pos.final_map);
}
