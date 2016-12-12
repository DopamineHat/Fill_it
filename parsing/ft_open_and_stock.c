/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2016/12/06 02:46:17 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

static t_dlist			ft_split_short(unsigned short shape)
{
	size_t	i;
	t_dlist	*new;

	i = 0;
	new = ft_init
	// while (i < 4)
	// {
		new->l1 = shape | new->l1;
		// i++;
	// }
		return (shape);
}

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
	size_t			i;
	unsigned short	binary_shape;

	i = 0;
	while (buf[i])
	{
		if ((i % 4 == 0 || i % 20 == 0) && buf[i] != '\n')
			return (ERROR);
		++i;
	}
	binary_shape = ft_convert_buf_to_short(buf);
	if (ft_check_if_valid(binary_shape) == -1)
		return (ERROR);
	return (binary_shape);
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
			return (ERROR);
		list = head->prev;
	}
	free(tmp);
	return (head);
}
