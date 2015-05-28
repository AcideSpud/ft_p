/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 23:13:29 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/10 19:40:09 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = (ft_strlen(s));
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		else
			len--;
	}
	return (NULL);
}
