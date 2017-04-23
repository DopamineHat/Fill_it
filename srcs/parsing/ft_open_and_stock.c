/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/23 08:38:13 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

static void				ft_init_map(t_tetri *tetri)
{
	int n;

	n = 0;
	if (!(tetri->map = (unsigned short *)malloc(16 * sizeof(unsigned short)))
		|| !(tetri->best_map = (unsigned short *)malloc(tetri->map_size * sizeof(unsigned short)))
		|| !(tetri->best_pos = (short*)malloc(sizeof(short) * tetri->nb)))
		exit(1);
		// del_stuff();
	while (++n < 16)
	{
		tetri->best_map[n] = 0;
		tetri->map[n] = 0;
	}
}

static unsigned short	ft_convert_to_short(char *buff)
{
	unsigned short	shape;
	size_t			i;

	shape = 0;
	i = 0;
	while (i != 20)
	{
		if (buff[i] == '#')
			shape += (1 << (15 - i + (i / 5)));
		++i;
	}
	return (shape);
}

static unsigned short	ft_check_one(char *buff, t_tetri *tetri)
{
	size_t			i;

	i = 0;
	while (buff[i])
	{
		if ((i + 1) % 5 == 0 && buff[i] != '\n')
			return (0);
		++i;
	}
	*tetri->tetri = ft_convert_to_short(buff);
	if ((*tetri->tetri = ft_check_if_valid(tetri)) == 0)
		return (0);
	return (*tetri->tetri);
}

int						ft_read_fd(int fd, t_tetri *tetri)
{
	int				ret;
	char			*buff;

	if (!(buff = ft_strnew(BUF_SIZE)) || fd == -1)
	  exit(EXIT_FAILURE);
	while ((ret = read(fd, buff, BUF_SIZE)) > 0)
	{
		if ((*(tetri->tetri) = ft_check_one(buff, tetri)) == 0)
		{
			ft_memdel((void **)&buff);
			return (-1);
		}
		tetri->tetri++;
		tetri->nb++;
	}
	tetri->pos = (short*)malloc(sizeof(short) * tetri->nb);
	if (!tetri->pos)
		exit(EXIT_FAILURE);
	ft_init_map(tetri);
	tetri->map_size = ft_sqrt(tetri->area);
	ft_looptetri(tetri);
	// ft_final_display(tetri);
	// ft_display_map(tetri);
	ft_memdel((void **)&buff);
	return (ret);
}
