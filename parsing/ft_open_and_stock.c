/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2016/12/01 23:43:43 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

static int	ft_check_valid_shape(char *buf, size_t i)
{
	if (buf[i] == )
}

static char	*ft_lst_pars_over_buf(t_dlist *list, char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (i % 21 == 0)
		{
			if (buf[i] == '\n')
			{
				list = list->next;
				// list->content = ft_strnew(21);
			}
		}
		if (i % 4 == 0 && buf[i] != '\n')
			return (ERROR);
		else if (buf[i] == '#' && ft_check_valid_shape(buf, i) == -1)
			return (ERROR)
	}
}

t_dlist	*ft_stock_fd(int fd, t_dlist *head)
{
	int		ret;
	char	*buf;
	t_dlist*list;
	
	list = head->next;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (BUF_SIZE >= 21)
			head->content = ft_lst_pars_over_buf(lst, buf);
		else
			head->content = ft_lst_pars_smaller_buf(lst, buf);
		if (head->content == NULL)
			return (ERROR);
		list = head->prev;
	}
	head->content = ft_strdup(tmp);
	free(tmp);
	return (head);
}
