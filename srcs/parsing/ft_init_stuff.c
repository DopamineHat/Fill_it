/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:02:13 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/23 06:57:54 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

int		ft_init_stuff(t_tetri *tetri)
{
	if (!(tetri->tetri = (unsigned short *)malloc(32 * sizeof(unsigned short)))
			|| !(tetri->tetriception = (unsigned short *)malloc(4
			* sizeof(unsigned short)))
			|| !(tetri->x = (int *)malloc(32 * sizeof(int))))
		exit(EXIT_FAILURE);
	tetri->area = 0;
	tetri->nb = 0;
	tetri->init_shift = 0;
	tetri->backtrack_count = 0;
	return (0);
}
