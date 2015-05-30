/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:08:08 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:08:09 by tapostin         ###   ########.fr       */
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
