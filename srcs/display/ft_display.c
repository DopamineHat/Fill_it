/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 03:33:47 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/20 09:12:52 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

int		ft_display(t_tetri *tetri)
{
	int i;

	i = 0;
	CHECK(DISPLAY);
	while (i < 16)
	{
		printf("%x\n", tetri->map[i]);
		++i;
	}
	return (1);
}

int ft_display_rec(t_tetri *tetri, int y)
{
	int bit;

	bit = 0;
	if (y == 16)
		return (tetri->i++);
	if (tetri->map[tetri->i] & 1)
		bit = 1;
	tetri->map[tetri->i] >>= 1;
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
	tetri->i = 0;
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
	if (tetri & 1)
		bit = 1;
	tetri >>= 1;
	if (i + 1 < 16)
		ft_print_tetri(tetri, i + 1);
	if (i % 4 == 0)
		ft_putchar('\n');
	if (bit == 1)
		ft_putchar('#');
	else
		ft_putchar('.');
}
