/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/03/02 03:07:36 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

unsigned short			ft_convert_buf_to_short(char *buf)
{
	unsigned short	shape;
	size_t			i;

	shape = 0;
	i = 0;
	while (i != 20)
	{
		if (buf[i] == '#')
			shape += (1 << (15 - i));
		i++;
	}
	return (shape);
}


static unsigned short	ft_lst_pars_buf(char *buf)
{
	size_t			i;
	unsigned short	tetri;
	int				area;

	i = 0;
	tetri = (unsigned short)malloc(sizeof(unsigned short));
	while (buf[i])
	{
		if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (0);
		++i;
	}
	tetri = ft_convert_buf_to_short(buf);
	if ((ft_check_if_valid(tetri, area)) == 0)
	{
		free((void*)&tetri);
		return (0);
	}
	return (tetri);
}

t_tetri		*ft_stock_fd(int fd, t_tetri *tetri_tab)
{
	int				ret;
	int				i;
	char			*buf;
	unsigned short	tetri;

	buf = (char*)malloc(sizeof(char) * 22);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[21] = '\0';
		if ((tetri = ft_lst_pars_buf(buf)) == 0)
		{
			free(buf);
			return (NULL);
		}
		tetri_tab[i] = ft_format_unsigned_short(tetri_tab[i], tetri);
		i++;
	}
	free(buf);
	if (ret == -1)
		return (NULL);
	return (tetri_tab);
}
