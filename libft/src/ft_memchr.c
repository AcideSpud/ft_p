/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:08:37 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/10 23:04:40 by ajulien          ###   ########.fr       */
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
