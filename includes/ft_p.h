/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapostin <tapostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 16:31:25 by tapostin          #+#    #+#             */
/*   Updated: 2015/05/15 14:43:06 by tapostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

typedef struct			s_serv
{
	int					port;
	int					sock;
	int					cs;
	unsigned	int		cslen;
	struct sockaddr_in	csin;
	struct	protoent	*proto;
	struct	sockaddr_in	sin;
}						t_serv;

typedef	struct			s_client
{
	int					port;
	int					sock;
	struct	protoent	*proto;
	struct	sockaddr_in	sin;
}						t_client;

void	usage_client(char *str);
void	usage_serveur(char *str);
int		create_client(char *addr, int port);
int		create_server(int port);

#endif
