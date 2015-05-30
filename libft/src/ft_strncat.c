/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:17:21 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:17:23 by tapostin         ###   ########.fr       */
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
