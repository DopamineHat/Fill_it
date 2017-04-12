/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 03:33:47 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/12 04:45:34 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

int		ft_display(t_tetri tetri)
{
	CHECK(COUCOUFDP);
	printf("%d\n", *tetri.map);
	return (1);
}
