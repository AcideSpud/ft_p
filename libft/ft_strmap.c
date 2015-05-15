/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:36:23 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 17:14:22 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		s2 = (char *)malloc(sizeof(*s2) * ft_strlen(s));
		if (!s2)
			return (NULL);
		while (s[i] != '\0')
		{
			s2[i] = f(s[i]);
			i++;
		}
		return (s2);
	}
	return (0);
}
