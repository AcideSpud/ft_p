/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:10:45 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:10:47 by tapostin         ###   ########.fr       */
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
