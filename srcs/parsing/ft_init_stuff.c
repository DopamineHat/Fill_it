/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:02:13 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/20 07:29:51 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

int		ft_init_stuff(t_tetri *tetri)
{
	int n;

	n = -1;
	if (!(tetri->tetri = (unsigned short *)malloc(32 * sizeof(unsigned short)))
			|| !(tetri->tetriception = (unsigned short *)malloc(4
			* sizeof(unsigned short)))
			|| !(tetri->map = (unsigned short *)malloc(16
			* sizeof(unsigned short)))
			|| !(tetri->x = (int *)malloc(32 * sizeof(int))))
		exit(EXIT_FAILURE);
	tetri->i = 0;
	tetri->area = 0;
	tetri->nb = 0;
	while (++n < 16)
		tetri->map[n] = 0;
	return (0);
}
