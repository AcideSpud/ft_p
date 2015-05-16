/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 20:57:46 by tapostin          #+#    #+#             */
/*   Updated: 2014/11/14 22:03:51 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p_it;
	t_list	*p_next;

	if (!alst || !*alst)
		return ;
	p_it = (*alst);
	p_next = (*alst)->next;
	ft_lstdelone(&p_it, del);
	if (p_next)
		ft_lstdel(&p_next, del);
	*alst = NULL;
}
