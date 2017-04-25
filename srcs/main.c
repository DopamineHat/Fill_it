/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:27:43 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/25 12:17:28 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fill_it.h"

int		main(int argc, char **argv)
{
	t_tetri *tetri;

	tetri = ft_init_stuff();
	if (argc != 2)
	{
		ft_putendl_fd("u wot m8", 2);
		return (1);
	}
	if (ft_read_fd(open(argv[1], O_RDONLY), tetri) == -1)
	{
		ft_putendl_fd("error", 2);
		return (1);
	}
	return (0);
}
