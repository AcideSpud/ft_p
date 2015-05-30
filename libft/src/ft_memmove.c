/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:03:37 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:03:40 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	if (!(temp = malloc(len * sizeof(*temp))))
		return (NULL);
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	free(temp);
	return (dst);
}
