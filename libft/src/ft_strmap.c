/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 04:11:46 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/14 16:36:53 by ajulien          ###   ########.fr       */
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
