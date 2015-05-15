/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:40:23 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 16:58:14 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
	char		*str1;
	char		*str2;
	char		*temp;
	size_t		i;

	i = 0;
	str1 = (char *)dst;
	str2 = (char *)src;
	if (str1 == NULL || str2 == NULL)
		return (0);
	temp = (char *)malloc(sizeof(*temp) * ft_strlen(str2));
	if (temp == NULL)
		return (NULL);
	temp = ft_strcpy(temp, str2);
	while (i < n)
	{
		str1[i] = temp[i];
		i++;
	}
	return (str1);
}
