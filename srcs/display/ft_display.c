/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 03:33:47 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/18 12:22:44 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

int		ft_display(t_tetri *tetri)
{
	int i;

	i = 0;
	CHECK(DISPLAY);
	while (i < 16)
	{
		printf("%x\n", tetri->map[i]);
		++i;
	}
	return (1);
}
