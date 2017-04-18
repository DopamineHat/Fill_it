/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:27:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/18 12:49:59 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fill_it.h"

int		main(int argc, char **argv)
{
	t_tetri tetri;

	ft_init_stuff(&tetri);
	if (argc != 2)
	{
		ft_putendl_fd("u wot m8", 2);
		return (1);
	}
	if (ft_read_fd(open(argv[1], O_RDONLY), &tetri) == -1)
	{
		ft_putendl_fd("error", 2);
		return (1);
	}
	return (0);
}
