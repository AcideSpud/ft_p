/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:25:23 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/09 15:24:11 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		cmp;
	char	*str;
	int		i;

	i = 0;
	cmp = 0;
	while (src[cmp] != '\0')
		cmp++;
	str = (char *)malloc(sizeof(char) * (cmp + 1));
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
