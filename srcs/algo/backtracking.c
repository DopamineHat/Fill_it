/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 02:17:54 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/29 03:29:49 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

void	rinit_map(t_tetri *tetri)
{
	int n;

	n = tetri->map_size + 2;
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

// int	ft_backtrack(t_tetri *tetri, int size, int failed_at_i, int first_fail)
// {
// 	rinit_map(tetri);
// 	tetri->init_shift++;
// 	if (tetri->init_shift > size)
// 	{
// 		tetri->backtrack_count--;
// 		tetri->init_shift = 0;
// 	}
// 	else if (first_fail == -1 || failed_at_i)
// 		tetri->backtrack_count = failed_at_i - 1;
// 	return (failed_at_i);
// }
