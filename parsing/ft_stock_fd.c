/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2016/12/01 19:52:52 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

t_dlist	*ft_stock_fd(int fd)
{
	int		ret;
	char	*buf;
	t_dlist	*head;
	char	*tmp;

	if ((head = ft_init_head("head")))
		return (ERROR);
	if ((fd = open(argv[1])) < 0)
		return (ERROR);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if ((tmp = ft_strjoin(tmp, buf)) == NULL)
			return (ERROR);
	}
	head->content = ft_strdup(tmp);
	free(tmp);
	return (head);
}