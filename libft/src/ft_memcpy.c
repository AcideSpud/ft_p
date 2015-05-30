/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:02:55 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:02:57 by tapostin         ###   ########.fr       */
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
