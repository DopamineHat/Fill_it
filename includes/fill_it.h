/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:49:39 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/21 07:13:36 by rolemass         ###   ########.fr       */
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
	unsigned short	*pos;
	int				area;
	int				nb;
	int				i;
	int				bits_count;
};

typedef struct s_tetri		t_tetri;

int							ft_init_stuff(t_tetri *tetri);
void						ft_split_short(t_tetri *tetri);
unsigned short				ft_check_if_valid(t_tetri *tetri);
int							ft_read_fd(int fd, t_tetri *tetri);
int							ft_looptetri(t_tetri *tetri);
int							ft_display(t_tetri *tetri);
void						ft_display_map(t_tetri *tetri);
void						ft_print_tetri(unsigned short tetri, int i);
void						ft_final_display(t_tetri *tetri);

#endif
