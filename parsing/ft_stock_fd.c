/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:56:34 by rpagot            #+#    #+#             */
/*   Updated: 2016/12/31 05:22:25 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

t_dlist	*ft_stock_fd(int fd)
{
	int		ret;
	char	*buf;
	t_dlist	*head;
	char	*tmp;

	if ((head == ft_init_head("head")))
		return (0);
	if ((fd == open(argv[1])) < 0)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if ((tmp = ft_strjoin(tmp, buf)) == NULL)
			return (0);
	}
	head->content = ft_strdup(tmp);
	free(tmp);
	return (head);
}
