/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:01:35 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:01:36 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pdst;
	unsigned char const	*psrc;
	unsigned char		cbis;
	size_t				i;

	if (!dst || !src)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char const *)src;
	cbis = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == cbis)
			return (dst + i + 1);
		else
			i++;
	}
	return (NULL);
}
