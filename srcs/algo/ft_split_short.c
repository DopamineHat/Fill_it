/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:05:37 by rpagot            #+#    #+#             */
/*   Updated: 2017/03/29 11:13:08 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

t_tetri		ft_split_short(t_tetri tetri)
{
	unsigned short tmp;

	tmp = *tetri.tetri >> 12;
	*tetri.tetriception++ = tmp << 12;
	tmp = *tetri.tetri >> 8;
	*tetri.tetriception++ = tmp << 12;
	tmp = *tetri.tetri >> 4;
	*tetri.tetriception++ = tmp << 12;
	*tetri.tetriception = *tetri.tetri << 12;
	return (tetri);
}
