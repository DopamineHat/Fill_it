/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:49:39 by rpagot            #+#    #+#             */
/*   Updated: 2017/05/04 05:18:19 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

#include "../Libft/includes/libft.h"

#include <stdio.h> //WARNIIIIIIIIIIIIIIING

# define BUF_SIZE 21

# define CHECK(x) do { ft_putendl("_______");	\
  ft_putendl(#x);					\
  ft_putendl("___________"); } while(0);


struct						s_block
{
	unsigned short line1;
	unsigned short line2;
	unsigned short line3;
	unsigned short line4;
};

struct						s_tetri
{
	unsigned short	*tetri;
	struct s_block	*block;
	unsigned short	*map;
	short			*pos;
	int				area;
	int				nb;
	int				map_size;
	unsigned short	*range;
};

typedef struct s_tetri		t_tetri;
typedef struct s_block		t_block;

t_tetri						*ft_init_stuff(void);
t_block						ft_split_short(t_block *restrict block, int n, unsigned short tetri);
unsigned short				ft_check_if_valid(t_tetri *tetri);
int							ft_read_fd(int fd, t_tetri *tetri);
int							ft_test_by_size(t_tetri *tetri);
int							ft_display(t_tetri *tetri);
void						ft_display_map(t_tetri *tetri);
void						ft_print_tetri(unsigned short tetri, int i);
void						ft_final_display(t_tetri *tetri);
void						ft_get_tetris_range(t_tetri *tetri);
int							ft_test_tetri(t_tetri *restrict tetri, int i, int x);
int							ft_backtrack(t_tetri *tetri, int size, int failed_at_i, int first_fail);

#endif
