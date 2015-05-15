#ifndef FT_P_H
# define FT_P_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "../libft/libft.h"

typedef struct			s_serv
{
	int					port;
	int					sock;
	int					cs;
	unsigned	int		cslen;
	struct sockaddr_in	csin;
	struct protoent		*proto;
	struct sockaddr_in	sin;
}						t_serv;

typedef	struct			s_client
{
	int					port;
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
}						t_client;

/*
**error_client.c
*/
void					usage_client(char *str);
void					parse_error(char *str);
void					too_many_argument(char *str);

/*
**error_serveur.c
*/
void					usage_serveur(char *str);
/*
**client.c
*/
int						create_client(char *addr, int port);
/*
**serveur.c
*/
int						create_server(int port);
/*
**hub_client.c
*/
void					hub_client(char *, t_client clt);
void					freetab(char **abc);
int						tablen(char **abc);
/*
**pwd_quit_client.c
*/
void					quit_hub(char **tab, t_client clt);
void					pwd_hub(char **tab, t_client clt);
/*
**cd_client.c
*/
void					cd_hub(char **tab, t_client clt);
/*
**ls_client.c
*/
void					ls_hub(char **tab, t_client clt);
/*
**put_client.c
*/
void					put_hub(char **tab, t_client clt);
/*
**get_client.c
*/
void					get_hub(char **tab, t_client clt);

#endif
