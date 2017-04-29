/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:05:37 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/28 03:31:09 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

void	ft_split_short(t_tetri *restrict tetri, int i)
{
	unsigned short tmp;

	tmp = tetri->tetri[i] >> 12;
	tetri->tetriception[0] = tmp << 12;
	tmp = tetri->tetri[i] >> 8;
	tetri->tetriception[1] = tmp << 12;
	tmp = tetri->tetri[i] >> 4;
	tetri->tetriception[2] = tmp << 12;
	tetri->tetriception[3] = tetri->tetri[i] << 12;
}
