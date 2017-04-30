/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 02:17:54 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/30 14:23:05 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

void	rinit_map(t_tetri *tetri)
{
	int n;

	n = tetri->map_size + 1;
	while (n >= 0)
	{
		tetri->map[n] = 0;
		n--;
	}
	n = 0;
	while (n < tetri->nb)
		tetri->pos[n++] = 0;
	// tetri->valid_map = 0;
}
