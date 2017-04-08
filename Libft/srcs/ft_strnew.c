/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:51:32 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:51:43 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	if (!(array = (char*)malloc(size + 1 * sizeof(char))))
		return (NULL);
	array[size + 1] = '\0';
	while (i <= size)
	{
		array[i] = '\0';
		++i;
	}
	return (array);
}
