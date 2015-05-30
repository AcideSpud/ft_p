/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:18:29 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:18:30 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	if (!dst || !src)
		return (NULL);
	if (ft_strlen(src) < n)
	{
		ft_bzero((void *)dst, n);
		return (ft_strcpy(dst, src));
	}
	else
		return ((char *)ft_memcpy((void *)dst, (void *)src, n));
}
