/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:39:01 by rolemass          #+#    #+#             */
/*   Updated: 2016/12/02 22:20:04 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fill_it.h"

t_dlist	*ft_create_tetri(void)
{
	t_dlist	*new;

	new = (t_dlist*)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->l1 = (unsigned int)malloc(4);
	new->l2 = (unsigned int)malloc(4);
	new->l3 = (unsigned int)malloc(4);
	new->l4 = (unsigned int)malloc(4);
	if (!new->l1 || !new->l2 || !new->l3 || new->l4)
		return (NULL);
	new->l1 = 0;
	new->l2 = 0;
	new->l3 = 0;
	new->l4 = 0;
	return (new);
}
