/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:42:42 by rpagot            #+#    #+#             */
/*   Updated: 2017/02/26 00:35:52 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

#include "Libft/includes/libft.h"

# define BUF_SIZE 21

struct	s_tetri
{
	unsigned short	l1;
	unsigned short	l2;
	unsigned short	l3;
	unsigned short	l4;
	int				x;
};

// struct	s_mlist
// {
// 	unsigned short	*tetripos;
// 	unsigned short	*prepos;
// 	struct s_mlist	*prev;
// 	struct s_mlist	*next;
// };


struct s_final_map
{
	char	**final_map;
	char	letter;
	int		x;
	int		y;
};

typedef struct s_dlist		t_tetri;
// typedef struct s_mlist		t_mlist;
typedef struct s_final_map	t_final_map;

unsigned short	ft_check_if_valid(unsigned short tetri, int area);
t_dlist			*ft_format_unsigned_short(t_dlist *list, unsigned short tetri);

#endif
