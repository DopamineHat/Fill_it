/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:37:41 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:37:42 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp;

	if ((tmp = (unsigned char *)ft_memalloc(len)) == NULL)
		;
	else
	{
		ft_memcpy(tmp, src, len);
		ft_memcpy(dst, tmp, len);
	}
	free(tmp);
	return ((unsigned char *)dst);
}
