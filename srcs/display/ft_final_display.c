/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 04:21:38 by rolemass          #+#    #+#             */
/*   Updated: 2017/05/03 09:41:51 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"

static char	*ft_init_tab(int size)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = (char*)ft_memalloc(sizeof(char) * size + 4)))
		exit(EXIT_FAILURE);
	while (i < size)
		tab[i++] = '.';
	// tab[i] = '\0';
	return (tab);
}

char	*ft_add_tetri_to_display(t_tetri *tetri, char letter, char *tab, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 15;
	while (j >= 0)
	{
		if (((tetri->tetri[n] >> i) & 1) && tetri->pos[n] > -1)
			tab[tetri->pos[n] + (j % 4) + (j / 4) * 16] = letter;
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
	size = tetri->map_size * 16;
	tab = ft_init_tab(size);
	while (i < tetri->nb && tetri->pos[i] > -1)
	{
		tab = ft_add_tetri_to_display(tetri, letter, tab, i);
		// tetri->pos++;
		letter++;
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
			ft_putchar('\n');
		ft_putchar(tab[i++]);
	}
	CHECK(WTF IS DISPLAYING);
	ft_memdel((void**)&tab);
}
