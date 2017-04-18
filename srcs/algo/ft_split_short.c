/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:05:37 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/18 11:42:15 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

int		ft_split_short(t_tetri *tetri)
{
	unsigned short tmp;

	tmp = *tetri->tetri >> 12;
	tetri->tetriception[0] = tmp << 12;
	tmp = *tetri->tetri >> 8;
	printf("tetriception0: %x\n", tetri->tetriception[0]);
	tetri->tetriception[1] = tmp << 12;
	printf("tetriception1: %x\n", tetri->tetriception[1]);
	tmp = *tetri->tetri >> 4;
	tetri->tetriception[2] = tmp << 12;
	printf("tetriception2: %x\n", tetri->tetriception[2]);
	tetri->tetriception[3] = *tetri->tetri << 12;
	printf("tetriception3: %x\n", tetri->tetriception[3]);
	return (0);
}
