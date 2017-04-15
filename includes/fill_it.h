/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:49:39 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/13 05:43:10 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

#include "../Libft/includes/libft.h"

# define BUF_SIZE 21

# define CHECK(x) do { ft_putendl("_______");	\
  ft_putendl(#x);					\
  ft_putendl("___________"); } while(0);

struct						s_tetri
{
	unsigned short	*tetri;
	unsigned short	*tetriception;
	int				*x;
	unsigned short	*map;
	int				area;
	int				i;
};

struct						s_final_map
{
	char	**final_map;
	char	letter;
	int		x;
};

struct						s_tlist
{
	unsigned short	l1;
	unsigned short	l2;
	unsigned short	l3;
	unsigned short	l4;
};

typedef struct s_tlist		t_tlist;
typedef struct s_tetri		t_tetri;
typedef struct s_final_map	t_final_map;

t_tetri						ft_split_short(t_tetri tetri);
unsigned short				ft_check_if_valid(t_tetri tetri);
int							ft_read_fd(int fd, t_tetri tetri);
int							ft_looptetri(t_tetri tetri);
int							ft_display(t_tetri tetri);

#endif
