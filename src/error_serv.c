#include <ft_p.h>

void	close_socket(t_serv clt)
{
	printf("Un client est MORT\n");
	close(clt.cs);
	exit(1);
}

void	usage_serveur(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}
