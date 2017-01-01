/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:53:11 by rolemass          #+#    #+#             */
/*   Updated: 2017/01/01 09:25:26 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

t_dlist	*ft_stock_valid(t_dlist *head)
{
	t_dlist	*list;
	size_t	i;

	i = 0;
	list = head->next;
	while (head->content[i])
	{
		if (head->content[i] == '#' && ft_check_if_valid == 0)
			return (0);
	}
}
