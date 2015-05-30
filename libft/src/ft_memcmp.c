/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:02:26 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:02:29 by tapostin         ###   ########.fr       */
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
