/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:16:40 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:16:42 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	new = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
