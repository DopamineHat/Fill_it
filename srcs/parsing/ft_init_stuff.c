/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:02:13 by rpagot            #+#    #+#             */
/*   Updated: 2017/05/04 02:16:26 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

t_tetri		*ft_init_stuff()
{
	t_tetri *tetri = NULL;

	if (!(tetri = (t_tetri*)ft_memalloc(sizeof(t_tetri)))
	 || !(tetri->tetri = (unsigned short *)ft_memalloc(32 * sizeof(unsigned short))))
		exit(EXIT_FAILURE);
	tetri->area = 0;
	tetri->nb = 0;
	tetri->map = NULL;
	tetri->pos = NULL;
	tetri->map_size = 0;
	return (tetri);
}
