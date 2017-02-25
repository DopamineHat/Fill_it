/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:40:04 by rpagot            #+#    #+#             */
/*   Updated: 2017/02/25 03:10:15 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

unsigned short	*ft_placetetri(unsigned short *prepos, unsigned short tetri)
{
	int x;

	x = 0;
	while (x < 256)
	{
		if ((*prepos ^ tetri) == (*prepos | tetri) && ((*prepos << (x % 16)
					>> (15 - (x % 16))) == 1))
			ft_verifytetri(
	*prepos++;
	++x;
	}

