/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 03:33:47 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/29 07:48:03 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

int ft_display_rec(t_tetri *tetri, int y)
{
	int bit;

	bit = 0;
	if (y == 16)
		return (tetri->x++);
	if (tetri->map[tetri->x] & 1)
		bit = 1;
	tetri->map[tetri->x] >>= 1;
	ft_display_rec(tetri, y + 1);
	if (bit == 1)
		ft_putchar('#');
	else
		ft_putchar('.');
	return (0);
}

void	ft_display_map(t_tetri *tetri)
{
	int i;
	int y;

	i = 0;
	y = 0;
	tetri->x = 0;
	while (i < 16)
	{
		ft_display_rec(tetri, y);
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_tetri(unsigned short tetri, int i)
{
	int bit;

	bit = 0;
	if (i == 0)
		ft_putchar('\n');
	if (tetri & 1)
		bit = 1;
	tetri >>= 1;
	if (i < 16)
		ft_print_tetri(tetri, i + 1);
	// if (i != 0 && i % 4 == 0)
	if (bit == 1)
		ft_putchar('#');
	else
		ft_putchar('.');
}
