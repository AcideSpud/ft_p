/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 17:46:57 by ajulien           #+#    #+#             */
/*   Updated: 2015/03/08 22:50:46 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrimchar(char const *str, char c)
{
	size_t	start;
	size_t	end;
	char	*new;
	char	*trav;

	start = 0;
	end = 0;
	trav = (char *)str;
	while (*(trav++) == c)
		start++;
	trav = (char *)str + ft_strlen(str) - 1;
	while (*(trav--) == c)
		end++;
	if (start + end == 0)
		return ((char *)str);
	if (start == ft_strlen(str))
		return (ft_strnew(0));
	if (!(new = ft_strnew(ft_strlen(str) - (start + end))))
		return (NULL);
	return (ft_strncpy(new, str + start, ft_strlen(str) - (start + end)));
}

static char	*ft_strdupchar(char **str, char c)
{
	size_t	len;
	size_t	i;
	char	*new;

	i = 0;
	len = 0;
	while ((*str)[i] != c && (*str)[i++])
		len++;
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = **str;
		(*str)++;
		i++;
	}
	while (**str == c)
		(*str)++;
	return (new);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		len;
	char	**tab;
	char	*new;

	if (!s)
		return (NULL);
	i = 1;
	len = 1;
	new = ft_strtrimchar(s, c);
	if (!(*new))
		len = 0;
	while (new[i])
	{
		if (new[i] == c && new[i - 1] != c)
			len++;
		i++;
	}
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		tab[i++] = ft_strdupchar(&new, c);
	return (tab);
}
