/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 01:29:11 by rolemass          #+#    #+#             */
/*   Updated: 2016/12/25 02:23:43 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// idee: Au moment de stocker les pieces, on prend les "coordonnees" et on lest stock dans la liste
// exemple:
// AAA
//  A
// Le premier point a check est en x = 1, y = 2

int		cmp_tetri_one(t_dlist *tetri, unsigned short to_cmp)
{
	unsigned short	tmp;
	int				i;
	int				j;

	j = 1;
	while (j < 5 && (i = tetri->prev->x + j) < MAP_SIZE)
	{
		tmp = (tetri->content >> i);
		if (tmp & to_cmp == 0)
			return (j);
		j++;
	}
	return (-1);
}

int		cmp_tetri_two(t_dlist *tetri, unsigned short to_cmp, int j)
{
	unsigned short	tmp;
	int				i;

	while (j < 5 && (i = tetri->prev->x + j) < MAP_SIZE)
	{
		tmp = (tetri->content >> i);
		if (tmp & to_cmp == 0)
			return (j);
		j++;
	}
	return (-1);
}

int		cmp_tetri_three(t_dlist *tetri, unsigned short to_cmp, int j)
{
	unsigned short	tmp;
	int				i;

	while (j < 5 && (i = tetri->prev->x + j) < MAP_SIZE)
	{
		tmp = (tetri->content >> i);
		if (tmp & to_cmp == 0)
			return (j);
		j++;
	}
	return (-1);
}

int		cmp_tetri_four(t_dlist *tetri, unsigned short to_cmp, int j)
{
	unsigned short	tmp;
	int				i;

	while (j < 5 && (i = tetri->prev->x + j) < MAP_SIZE)
	{
		tmp = (tetri->content >> i);
		if (tmp & to_cmp == 0)
			return (j);
		j++;
	}
	return (-1);
}
