/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:53:11 by rolemass          #+#    #+#             */
/*   Updated: 2016/12/01 19:59:47 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_stock_valid(t_dlist *head);
{
	t_dlist	*list;
	size_t	i;

	i = 0;
	list = head->next;
	while (head->content[i])
	{
		if (head->content[i] == '#' && ft_check_valid_shape == ERROR)
			return (ERROR);
		if (i % 4 == 0)
	}
}