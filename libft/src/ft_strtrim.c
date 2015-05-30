/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:22:27 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:22:29 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == 9 || s[start] == 10 || s[start] == 32) && s[start])
		start++;
	while ((s[end] == 9 || s[end] == 10 || s[end] == 32) && end >= 0)
		end--;
	if (end < 0)
		return (ft_strnew(0));
	len = (end + 1) - start;
	if (!(new = ft_strnew(len)))
		return (NULL);
	strncpy(new, (s + start), len);
	return (new);
}
