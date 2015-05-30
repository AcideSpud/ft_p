/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:21:12 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:21:13 by tapostin         ###   ########.fr       */
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
