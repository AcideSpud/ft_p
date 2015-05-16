/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:39:09 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 17:16:21 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		o;

	o = 0;
	i = 0;
	if (!s)
		return (NULL);
	j = strlen(s);
	str = (char *)malloc(j + 1);
	if (!str)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == '\0')
		j--;
	while (i <= j)
	{
		str[o] = s[i];
		i++;
		o++;
	}
	str[o] = '\0';
	return (str);
}
