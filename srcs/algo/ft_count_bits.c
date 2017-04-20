/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 06:57:20 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/20 07:26:31 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fill_it.h"

void	ft_count_bits(t_tetri *tetri)
{
	int	i;
	unsigned short	tmp;
	int count;

	i = 0;
	while (i < 4)
	{
		count = 0;
		tmp = tetri->tetriception[i];
		while (tmp > 0)
		{
			if (tetri->tetriception & 1)
				count++;
			tmp >>= 1;
		}
		if (count > tetri->bits_count)
			tetri->bits_count = count;
		i++;
	}
}
