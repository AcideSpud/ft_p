/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 19:00:59 by ajulien           #+#    #+#             */
/*   Updated: 2015/03/08 22:47:47 by ajulien          ###   ########.fr       */
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
