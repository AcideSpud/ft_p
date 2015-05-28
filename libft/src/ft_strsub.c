/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:35:22 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/14 18:17:22 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	ft_strncpy(new, (s + start), len);
	return (new);
}
