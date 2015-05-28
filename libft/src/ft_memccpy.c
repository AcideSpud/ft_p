/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:17:56 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/10 23:03:39 by ajulien          ###   ########.fr       */
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
