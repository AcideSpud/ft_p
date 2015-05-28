/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:56:07 by ajulien           #+#    #+#             */
/*   Updated: 2014/12/12 17:56:18 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strfsplit(char **s, char c, int pfree)
{
	char	**ret;

	ret = ft_strsplit((char const *)*s, c);
	if (pfree == 1)
	{
		free(*s);
		*s = NULL;
	}
	return (ret);
}
