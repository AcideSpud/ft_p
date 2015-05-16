/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:49:03 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/13 18:26:33 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char*)s1);
	while (s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
		if (!s2[j])
			return ((char*)s1 + (i - (j - 1)));
		i++;
	}
	return (NULL);
}
