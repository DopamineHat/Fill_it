/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:26:15 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/13 05:52:07 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fill_it.h"

int		main(int argc, char **argv)
{
	t_tetri tetri;

	if (!(tetri.tetri = (unsigned short *)malloc(32 * sizeof(unsigned short)))
			|| !(tetri.tetriception = (unsigned short *)malloc(4
			* sizeof(unsigned short)))
			|| !(tetri.map = (unsigned short *)malloc(16
			* sizeof(unsigned short)))
			|| !(tetri.x = (int *)malloc(32 * sizeof(int))))
		exit(EXIT_FAILURE);
	tetri.i = 0;
	tetri.area = 0;
	if (argc != 2)
	{
		ft_putendl_fd("u wot m8", 2);
		return (1);
	}
	if (ft_read_fd(open(argv[1], O_RDONLY), tetri) == -1)
	{
		ft_putendl_fd("error?", 2);
		return (1);
	}
	return (0);
}
