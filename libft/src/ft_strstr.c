/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:21:57 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:21:58 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (!s2[j])
		return ((char *)s1 + (i - j));
	return (NULL);
}
