/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:35:05 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:35:08 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *dst;

	dst = 0;
	if ((dst = malloc(size * sizeof(char))) == NULL)
		return (NULL);
	if (dst)
		dst = ft_memset(dst, 0, size);
	return (dst);
}
