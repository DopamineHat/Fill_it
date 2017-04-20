/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:05:37 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/20 07:44:41 by rolemass         ###   ########.fr       */
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
	tetri->tetriception[1] = tmp << 12;
	tmp = *tetri->tetri >> 4;
	tetri->tetriception[2] = tmp << 12;
	tetri->tetriception[3] = *tetri->tetri << 12;
	return (0);
}
