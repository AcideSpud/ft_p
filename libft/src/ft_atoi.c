/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 19:54:20 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 19:54:24 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				digit;
	int				sign;
	int				result;

	result = 0;
	digit = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\r' || *str == '\f')
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str) && *str)
	{
		digit = (*str - '0');
		result = (result * 10) + digit;
		str++;
	}
	return (result * sign);
}
