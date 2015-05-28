/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:18:59 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/14 16:30:24 by ajulien          ###   ########.fr       */
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
