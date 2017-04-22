/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/22 06:07:53 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

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
		tetri->i++;
	}
	tetri->nb = tetri->i;
	tetri->pos = (unsigned short*)malloc(sizeof(unsigned short) * tetri->nb);
	if (!tetri->pos)
		exit(EXIT_FAILURE);
	ft_looptetri(tetri);
	ft_memdel((void **)&buff);
	ft_final_display(tetri);
	printf("tetri->count_bitss %d\n", tetri->bits_count);
	printf("tetri->nb: %d\n", tetri->nb);
	// ft_display_map(tetri);
	return (ret);
}
