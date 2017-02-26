/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:40:04 by rpagot            #+#    #+#             */
/*   Updated: 2017/02/26 04:09:48 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

unsigned short	*ft_placetetri(unsigned short *prepos, unsigned short *tetri)
{
	int x;
	int tmp;

	x = 0;
	tmp = 0;
	while (x < 256)
	{
		tmp = x;
		while (tmp < 16)
		{
			tmp -= 16;
			tetri++;
		}
		if ((*prepos & *tetri) == 0)
			ft_verifytetri(unsigned short *prepos, x);
		prepos++;
		++x;
	}
}

