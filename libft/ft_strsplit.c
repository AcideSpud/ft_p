/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 19:03:06 by tapostin          #+#    #+#             */
/*   Updated: 2015/04/22 18:23:04 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strsubb(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * len + 1);
	while (start < len)
	{
		*str = s[start];
		start++;
		str = str + 1;
	}
	*str = '\0';
	return (str - len);
}

static int	ft_count_word(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] != '\0' || s[i - 1] != c)
			j++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	l = ft_count_word(s, c);
	str = (char **)malloc(sizeof(char *) * l + 1);
	while (i < l)
	{
		j = 0;
		while (*s && *s == c)
			s = s + 1;
		while (*(s + j) && *(s + j) != c)
			j++;
		*(str++) = ft_strsubb(s, 0, j);
		s = s + j;
		i++;
	}
	*str = NULL;
	return (str - l);
}
