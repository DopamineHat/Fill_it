/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/01/01 09:17:37 by rpagot           ###   ########.fr       */
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
	static unsigned short	tetri;
	static int				area;

	i = 0;
	while (buf[i])
	{
		if ((i % 4 == 0 || i % 20 == 0) && buf[i] != '\n')
			return (0);
		++i;
	}
	tetri = ft_convert_buf_to_short(buf);
	ft_check_if_valid(tetri, area);
	return (tetri);
}

t_dlist		*ft_stock_fd(int fd, t_dlist *head)
{
	int		ret;
	char	*buf;
	t_dlist	*list;
	
	list = head->next;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		head->content = ft_lst_pars_buf(lst, buf);
		if (head->content == NULL)
			return (0);
		list = head->prev;
	}
	free(tmp);
	return (head);
}
