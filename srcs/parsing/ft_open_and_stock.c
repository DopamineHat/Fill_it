/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:31:59 by rolemass          #+#    #+#             */
/*   Updated: 2017/04/08 21:43:48 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fill_it.h"
#include <stdio.h>

static unsigned short	ft_convert_to_short(char *buff)
{
	unsigned short	shape;
	size_t			i;

	// shape = (unsigned short *)malloc(sizeof(unsigned short));
	shape = 0;
	i = 0;
	ft_putstr(buff);
	while (i != 20)
	{
		// printf("coucou\n");
		if (buff[i] == '#')
			shape += (1 << (15 - i + (i / 5)));
		++i;
		// printf("%u\n", *shape);
	}
	return (shape);
}

static unsigned short	ft_check_one(char *buff, t_tetri tetri)
{
	size_t			i;

	i = 0;
	CHECK(ENTERED WHILE);
	while (buff[i])
	{
	  CHECK(Entered loop);
		if ((i + 1) % 5 == 0 && buff[i] != '\n')
			return (0);
		++i;
		CHECK(end loop);
	}
	CHECK(EXITED);
	*tetri.tetri = ft_convert_to_short(buff);
	printf("%u\n", *tetri.tetri);
	CHECK(EXITED FT_CONVERT_TO_SHORT);
	if (ft_check_if_valid(tetri) == 0)
		return (0);
	CHECK(EXITED FT_CHECK_IF_VALID);
	return (*tetri.tetri);
}

int						ft_read_fd(int fd, t_tetri tetri)
{
	int				ret;
	int				i;
	char			*buff;

	i = 0;
	if (!(buff = ft_strnew(BUF_SIZE)))
	  exit(EXIT_FAILURE);
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buff, BUF_SIZE)) > 0)
	{
	  CHECK(TEST);
	  
		if ((*tetri.tetri++ = ft_check_one(buff, tetri)) == 0)
		{
		  // CHECK(TEST);

			ft_memdel((void **)&buff);
			ft_split_short(tetri);
			return (-1);
		}
		CHECK(YOU WOT M8);
		++i;
	}
	ft_memdel((void **)&buff);
	return (ret);
}