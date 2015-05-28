/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 23:01:33 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/07 01:08:41 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= (ft_strlen(s) + 1))
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		else
			i++;
	}
	return (NULL);
}
