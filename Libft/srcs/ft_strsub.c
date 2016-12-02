/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 22:26:01 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 22:26:03 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*array;

	if (!(s))
		return (NULL);
	i = 0;
	if (!(array = (char*)malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (len > 0)
	{
		array[i++] = s[start++];
		--len;
	}
	array[i] = '\0';
	return (array);
}
