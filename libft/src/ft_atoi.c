/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 02:28:17 by ajulien           #+#    #+#             */
/*   Updated: 2014/11/14 14:39:58 by ajulien          ###   ########.fr       */
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
