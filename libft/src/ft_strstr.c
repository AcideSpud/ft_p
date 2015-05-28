/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:56:22 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/15 16:38:37 by ajulien          ###   ########.fr       */
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
