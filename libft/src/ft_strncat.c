/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:46:46 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/14 20:28:03 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	len;

	len = (ft_strlen(dst) + n);
	ft_strncpy((dst + ft_strlen(dst)), src, n);
	dst[len] = '\0';
	return (dst);
}
