/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:05:37 by rpagot            #+#    #+#             */
/*   Updated: 2017/05/04 01:55:01 by rolemass         ###   ########.fr       */
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
	return (block[i]);
}
