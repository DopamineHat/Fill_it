/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/02/24 20:09:53 by rolemass         ###   ########.fr       */
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
		if (buf[i] == '#')
			shape += 1 << (15 - i++);
	return (shape);
}


static unsigned short	ft_lst_pars_buf(t_dlist *list, char *buf)
{
	size_t					i;
	unsigned short	tetri;
	int				area;

	i = 0;
	tetri = (unsigned short)malloc(sizeof(unsigned short));
	while (buf[i])
	{
		if ((i % 4 == 0 || i % 20 == 0) && buf[i] != '\n')
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

t_dlist		*ft_stock_fd(int fd, t_dlist *head)
{
	int				ret;
	char			*buf;
	unsigned short	tetri;
	t_dlist	*list;
	
	list = head->next;
	buf = (char*)malloc(sizeof(char) * 21);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if ((tetri = ft_lst_pars_buf(list, buf)) == 0)
		{
			free(buf);
			return (NULL);
		}
		list = ft_format_unsigned_short(list, tetri);
		list = head->next;
	}
	free(buf);
	if (ret == -1)
		return (NULL);
	return (head);
}
