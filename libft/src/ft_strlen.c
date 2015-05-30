/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:12:51 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 20:12:52 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(char const *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (*(s++))
		len++;
	return (len);
}
