/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:41:19 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 16:56:02 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*t;

	t = (unsigned char*)b;
	if (!t)
		return (NULL);
	while (n)
	{
		*(t++) = c;
		n--;
	}
	return (b);
}
