/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:16:25 by rolemass          #+#    #+#             */
/*   Updated: 2017/02/24 22:40:08 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it.h"

t_mlist	*ft_init_map()
{
	t_mlist	*head;

	if ((head = (t_mlist*)malloc(sizeof(t_mlist))) == NULL)
		return (NULL);
	head->prepos = NULL;
	head->tetripos = NULL;
	head->prev = head;
	head->next = head;
	return (head);
}

t_mlist	*ft_create_new_map(t_mlist *head, unsigned short *prepos)
{
	t_mlist	*new;

	if ((new = (t_mlist*)malloc(sizeof(t_mlist))) == NULL)
		return (NULL);
	new->prepos = prepos;
	new->tetripos = NULL;
	head->prev->next = new;
	new->prev = head->prev;
	new->next->head;
	head->prev = new;
	return (new);
}