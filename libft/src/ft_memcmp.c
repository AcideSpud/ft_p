/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:28:51 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/10 23:05:20 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < len && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
		i++;
	if (i == len)
		return (0);
	return ((int)(*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i)));
}
