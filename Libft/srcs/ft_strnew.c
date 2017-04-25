/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:51:32 by rpagot            #+#    #+#             */
/*   Updated: 2017/04/25 13:53:14 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	if (!(array = (char*)malloc(size * sizeof(char) + 1)))
		return (NULL);
	array[size] = '\0';
	while (i < size)
	{
		array[i] = '\0';
		++i;
	}
	return (array);
}
