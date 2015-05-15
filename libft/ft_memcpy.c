/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:38:23 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 16:57:56 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dt;
	const char	*sr;

	dt = dest;
	sr = src;
	while (n)
	{
		*dt++ = *sr++;
		n--;
	}
	return (dest);
}
