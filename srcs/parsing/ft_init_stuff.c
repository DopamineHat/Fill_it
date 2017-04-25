/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:02:13 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/25 13:50:06 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

t_tetri		*ft_init_stuff()
{
	t_tetri *tetri = NULL;

	if (!(tetri = (t_tetri*)ft_memalloc(sizeof(t_tetri)))
	 || !(tetri->tetri = (unsigned short *)ft_memalloc(32 * sizeof(unsigned short)))
	|| !(tetri->tetriception = (unsigned short *)ft_memalloc(4
	 * sizeof(unsigned short))))
		exit(EXIT_FAILURE);
	tetri->area = 0;
	tetri->nb = 0;
	// tetri->tetri = NULL;
	// tetri->tetriception = NULL;
	tetri->best_pos = NULL;
	tetri->map = NULL;
	tetri->pos = NULL;
	tetri->init_shift = 0;
	tetri->backtrack_count = 0;
	tetri->x = 0;
	tetri->valid_map = 0;
	tetri->map_size = 0;
	tetri->bits_count = 0;
	// printf("%p__________\n", tetri->tetri);
	return (tetri);
}
