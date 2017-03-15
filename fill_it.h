/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:42:42 by rpagot            #+#    #+#             */
/*   Updated: 2017/03/15 08:26:05 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

#include "Libft/includes/libft.h"

# define BUF_SIZE 21

struct	s_tetri
{
	unsigned short	*tetri;
	int				x;
	unsigned short *map;
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

typedef struct s_tetri		t_tetri;
// typedef struct s_mlist		t_mlist;
typedef struct s_final_map	t_final_map;

unsigned short	ft_check_if_valid(unsigned short tetri, int area);
t_tetri			ft_format_unsigned_short(t_tetri to_split, unsigned short tetri);
char			**ft_format_final_map(t_tetri *tab, int size);
t_tetri			ft_format_unsigned_short(t_tetri to_split, unsigned short tetri);
t_tetri			*ft_stock_fd(int fd, t_tetri *tetri_tab);
int				ft_looptetri(t_tetri tetri);

#endif
