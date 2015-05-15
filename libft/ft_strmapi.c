/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:46:17 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 17:14:52 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		s2 = (char *)malloc(sizeof(char*) * ft_strlen(s));
		if (s2 == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			s2[i] = f(i, s[i]);
			i++;
		}
		return (s2);
	}
	return (0);
}
