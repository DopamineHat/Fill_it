/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:49:39 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/27 08:09:35 by rolemass         ###   ########.fr       */
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

struct						s_tetri
{
	unsigned short	*tetri;
	unsigned short	*tetriception;
	int				x;
	int				valid_map;
	short			*best_pos;
	unsigned short	*map;
	short			*pos;
	int				backtrack_count;
	int				init_shift;
	int				area;
	int				nb;
	int				map_size;
	int				bits_count;
};

typedef struct s_tetri		t_tetri;

t_tetri						*ft_init_stuff(void);
void						ft_split_short(t_tetri *tetri, int n);
unsigned short				ft_check_if_valid(t_tetri *tetri);
int							ft_read_fd(int fd, t_tetri *tetri);
int							ft_looptetri(t_tetri *tetri);
int							ft_display(t_tetri *tetri);
void						ft_display_map(t_tetri *tetri);
void						ft_print_tetri(unsigned short tetri, int i);
void						ft_final_display(t_tetri *tetri);
void						ft_count_bits(t_tetri *tetri);
int							ft_place_tetri(t_tetri *tetri, int n, int size);
int							ft_backtrack(t_tetri *tetri, int size);
void						rinit_map(t_tetri *tetri);


#endif
