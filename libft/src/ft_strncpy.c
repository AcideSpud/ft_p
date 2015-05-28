/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:46:40 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/20 18:42:49 by ajulien          ###   ########.fr       */
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
