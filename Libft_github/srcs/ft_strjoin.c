/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:47:55 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:47:57 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*array;

	if (!(s1) || !(s2))
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1[i])
		i++;
	while (s2[i2])
		++i2;
	if (!(array = (char*)malloc(i + i2 * sizeof(char))))
		return (NULL);
	i2 = 0;
	while (s1[i2])
	{
		array[i2] = s1[i2];
		++i2;
	}
	i2 = 0;
	while (s2[i2])
		array[i++] = s2[i2++];
	array[i] = '\0';
	return (array);
}
