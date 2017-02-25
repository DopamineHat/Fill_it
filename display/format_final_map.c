/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_final_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 03:21:26 by rolemass          #+#    #+#             */
/*   Updated: 2017/02/25 04:55:20 by rolemass         ###   ########.fr       */
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

char		**ft_format_final_map(t_mlist *head, t_final_map pos, int size)
{
	t_final_map	**pos;
	int			count;

	if (!(final_map = init_final_map(size)))
		return (NULL);
	while (pos.x < size)
	{
		head = head->next;
		count = 0;
		while (head->tetripos[pos.x] == 0)
			pos.x++;
		while ((head->tetripos[pos.x] << 1) > 0 && count++) //verif le nb
		{
			if (head->tetripos[pos.x] > 225)
			{
				pos.final_map[pos.x][pos.y] = pos.letter;
				count++;
			}
			pos.y++;
		}
	}
	return (final_map);
}