/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:36:35 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 17:04:01 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str1;
	size_t			i;
	unsigned char	c_tmp;

	c_tmp = (unsigned char)c;
	str1 = (unsigned char *)s;
	i = 0;
	if (str1 == NULL)
		return (NULL);
	while (i < n)
	{
		if (str1[i] == c_tmp)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
