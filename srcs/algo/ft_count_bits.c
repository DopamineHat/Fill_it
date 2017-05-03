/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 06:57:20 by rolemass          #+#    #+#             */
/*   Updated: 2017/05/03 09:21:35 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static int	ft_count_bits(unsigned short line)
{
	int				i;
	int				count;
	unsigned short	tmp;

	i = 0;
	count = 0;
	tmp = line;
	while (i < 16 && tmp > 0)
	{
		if (tmp & 1)
		{
			while (i < 16)
			{
				count++;
				i++;
			}
		}
		tmp >>= 1;
		i++;
	}
	return (count);
}


void	ft_get_tetris_range(t_tetri *tetri)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < tetri->nb)
	{
		if ((count = ft_count_bits(tetri->block[i].line1)) > tetri->range[i])
			tetri->range[i] = count;
		if ((count = ft_count_bits(tetri->block[i].line2)) > tetri->range[i])
			tetri->range[i] = count;
		if ((count = ft_count_bits(tetri->block[i].line3)) > tetri->range[i])
			tetri->range[i] = count;
		if ((count = ft_count_bits(tetri->block[i].line4)) > tetri->range[i])
			tetri->range[i] = count;
		i++;
	}
}
