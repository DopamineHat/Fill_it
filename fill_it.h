/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:42:42 by rpagot            #+#    #+#             */
/*   Updated: 2017/02/23 18:25:57 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

#include "Libft/includes/libft.h"

# define BUF_SIZE 21


struct	s_dlist
{
	unsigned short	l1;
	unsigned short	l2;
	unsigned short	l3;
	unsigned short	l4;
	struct s_dlist	*prev;
	struct s_dlist	*next;
};

typedef struct s_dlist	t_dlist;

unsigned short		ft_check_if_valid(unsigned short tetri, int area);
t_dlist				*ft_format_unsigned_short(t_dlist *list, unsigned short tetri);

#endif