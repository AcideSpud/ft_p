/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:01:14 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:01:15 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*r;

	if (!size)
		return (NULL);
	if (!(r = malloc(size)))
		return (NULL);
	ft_bzero(r, size);
	return (r);
}
