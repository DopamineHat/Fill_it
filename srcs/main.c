/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:26:15 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/08 19:17:44 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fill_it.h"

int		main(int argc, char **argv)
{
	t_tetri tetri;

	if (!((tetri.tetri = (unsigned short *)malloc(32 * sizeof(unsigned short)))
			&& (tetri.tetriception = (unsigned short *)malloc(4
			* sizeof(unsigned short)))
			&& (tetri.map = (unsigned short *)malloc(16
			* sizeof(unsigned short)))))
		exit(EXIT_FAILURE);
	tetri.tetri = NULL;
	tetri.tetriception = NULL;
	tetri.x = 0;
	tetri.map = NULL;
	tetri.area = 0;
	if (argc != 2)
	{
		ft_putstr("u wot m8");
		return (1);
	}
	if (ft_read_fd(open(argv[1], O_RDONLY), tetri) == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
