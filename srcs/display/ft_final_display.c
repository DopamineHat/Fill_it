/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 04:21:38 by rolemass          #+#    #+#             */
/*   Updated: 2017/05/06 20:25:25 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static char	*ft_init_tab(int size, t_tetri *tetri)
{
	int		i;
	char	*tab;

	i = 1;
	if (!(tab = (char*)ft_memalloc(sizeof(char) * size + 4)))
		exit(EXIT_FAILURE);
	while (i < size + 1)
	{
		if (i > 0 && i % (tetri->map_size + 1) == 0)
			tab[i] = '\n';
		else
			tab[i] = '.';
		i++;
	}
	return (tab);
}

static char	*ft_add_tetri_to_tab(t_tetri *tetri, char letter, char *tab, int n)
{
	int	i;
	int	j;
	int pos;

	i = 0;
	j = 15;
	while (j >= 0)
	{
		if (((tetri->tetri[n] >> i) & 1))
		{
			pos = tetri->pos[n] / 16 * (tetri->map_size + 1)
			+ tetri->pos[n] % 16 + j / 4 * (tetri->map_size + 1) + j % 4 + 1;
			tab[pos] = letter;
		}
		j--;
		i++;
	}
	return (tab);
}

void		ft_final_display(t_tetri *tetri)
{
	int		i;
	char	letter;
	int		size;
	char	*tab;

	i = 0;
	letter = 'A';
	size = tetri->map_size * (tetri->map_size + 1);
	tab = ft_init_tab(size, tetri);
	while (i < tetri->nb)
	{
		tab = ft_add_tetri_to_tab(tetri, letter, tab, i);
		letter++;
		i++;
	}
	i = 1;
	tab++;
	write(1, tab, size);
	exit(1);
}
