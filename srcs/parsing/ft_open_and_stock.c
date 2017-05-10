/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/05/10 13:18:05 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

static void				ft_init_map(t_tetri *tetri)
{
	int n;

	n = 0;
	if (!(tetri->map = (unsigned short *)malloc(16 * sizeof(unsigned short)))
		|| !(tetri->pos = (short*)malloc(sizeof(short) * tetri->nb))
		|| !(tetri->block = (t_block*)malloc(sizeof(t_block) * tetri->nb))
		|| !(tetri->range = (unsigned short*)
			malloc(sizeof(unsigned short) * tetri->nb)))
		exit(1);
	while (++n < 16)
		tetri->map[n] = 0;
	n = 0;
	while (n < tetri->nb)
	{
		tetri->range[n] = 0;
		tetri->block[n] = ft_split_short(tetri->block, n, tetri->tetri[n]);
		n++;
	}
	ft_get_tetris_range(tetri);
	n = 0;
	while (n < tetri->nb)
		tetri->pos[n++] = -1;
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
		if (((i + 1) % 5 == 0 && buff[i] != '\n')
				|| ((i + 1) % 5 != 0 && i != 20
				&& buff[i] != '.' && buff[i] != '#'))
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
	int				retprev;
	char			*buff;

	retprev = 0;
	if (!(buff = ft_strnew(BUF_SIZE + 1)) || fd < 0)
		return (-1);
	while ((ret = read(fd, buff, BUF_SIZE)) > 0)
	{
		retprev = ret;
		if (ret < 20 || ((*(tetri->tetri) = ft_check_one(buff, tetri)) == 0))
			return (-1);
		tetri->tetri++;
		tetri->nb++;
		if (ret == 20 && (ret = read(fd, buff, BUF_SIZE) != 0))
			return (-1);
	}
	if (ret < 0 || retprev == 21 || retprev == 0)
		return (-1);
	tetri->tetri -= tetri->nb;
	ft_init_map(tetri);
	ft_memdel((void **)&buff);
	tetri->map_size = ft_sqrt(tetri->map_size - (tetri->area / 2));
	ft_test_by_size(tetri);
	ft_final_display(tetri);
	return (ret);
}
