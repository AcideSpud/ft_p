/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:51:53 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/30 23:33:55 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pdst;

	if (!dst || !src)
		return (NULL);
	i = 0;
	pdst = (char *)dst;
	while (i < n)
	{
		pdst[i] = *((char *)src + i);
		i++;
	}
	return (dst);
}
