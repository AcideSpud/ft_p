/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:01:51 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:01:53 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cbis;
	size_t			i;
	unsigned char	*s2;

	if (!s)
		return (NULL);
	s2 = (unsigned char *)s;
	cbis = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s2[i] == cbis)
			return ((void *)s + i);
		else
			i++;
	}
	return (NULL);
}
