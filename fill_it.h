/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:42:42 by rpagot            #+#    #+#             */
/*   Updated: 2017/02/24 22:20:32 by rpagot           ###   ########.fr       */
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

struct	s_mlist
{
	unsigned short	*tetripos;
	unsigned short	*prepos;
	struct s_mlist	*prev;
	struct s_mlist	*next;
};

typedef struct s_dlist	t_dlist;
typedef struct s_mlist	t_mlist;
unsigned short	ft_check_if_valid(unsigned short tetri, int area);
t_dlist			*ft_format_unsigned_short(t_dlist *list, unsigned short tetri);

#endif
