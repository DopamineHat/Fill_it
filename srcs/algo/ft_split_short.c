/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:05:37 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/30 14:11:36 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

t_block	ft_split_short(t_block *block, int i, unsigned short tetri)
{
	unsigned short tmp;

	tmp = tetri >> 12;
	block[i].line1 = tmp << 12;
	tmp = tetri >> 8;
	block[i].line2 = tmp << 12;
	tmp = tetri >> 4;
	block[i].line3 = tmp << 12;
	block[i].line4 = tetri << 12;
	// printf(" block %u\n", tetri->block[0].line);
	return (block[i]);
}
