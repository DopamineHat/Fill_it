/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:42:42 by rpagot            #+#    #+#             */
/*   Updated: 2016/12/03 00:39:06 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/includes/libft.h"

struct	s_dlist
{
	unsigned l1:4;
	unsigned l2:4;
	unsigned l3:4;
	unsigned l4:4;
	struct s_dlist	*prev;
	struct s_dlist	*next;
};

typedef struct s_dlist	t_dlist;

