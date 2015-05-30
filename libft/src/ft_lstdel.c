/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 19:58:05 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/06 19:58:07 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*n;
	t_list	*tmp;

	if (!alst || !(*alst))
		return ;
	n = *alst;
	while (n)
	{
		del(n->content, n->content_size);
		tmp = n->next;
		free(n);
		n = tmp;
	}
	*alst = NULL;
}
