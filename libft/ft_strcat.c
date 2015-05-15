/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:36:13 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 19:24:42 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
		i = i + 1;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j = j + 1;
	}
	s1[i + j] = '\0';
	return (s1);
}