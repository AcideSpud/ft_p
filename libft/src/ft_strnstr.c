/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:36:49 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/13 17:45:43 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	lens2;
	size_t	i;
	size_t	j;

	lens2 = ft_strlen(s2);
	i = 0;
	j = 0;
	if (lens2 == 0)
		return ((char *)s1);
	while (s1[i] && s2[j] && i < n)
	{
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (!s2[j])
		return ((char *)s1 + (i - j));
	else
		return (NULL);
}
