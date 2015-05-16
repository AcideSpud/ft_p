/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:23:55 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 17:12:59 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*memory;
	unsigned int	counter;
	char			*e;

	counter = 0;
	if (size == 0)
		return (NULL);
	memory = (void *)malloc(size);
	if (!memory)
		return (NULL);
	e = (char *)memory;
	if (memory != NULL)
	{
		while (counter++ < size)
			*e++ = 0;
	}
	return (memory);
}
