/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:52:23 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 16:58:05 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	str = (unsigned char *)dst;
	str1 = (unsigned char *)src;
	i = 0;
	if (str == NULL || str1 == NULL)
		return (0);
	while (i < n)
	{
		str[i] = str1[i];
		if (str[i] == c)
			return (str + i + 1);
		i++;
	}
	return (0);
}
