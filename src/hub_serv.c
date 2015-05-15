#include <ft_p.h>

void	hub_serv(char *str, t_serv clt)
{
	char	**tabcmd;

	tabcmd = ft_strsplit(str, ' ');
	if (ft_strcmp(tabcmd[0], "quit") == 0)
		close_socket(clt);
	if (ft_strcmp(tabcmd[0], "cd") == 0)
		return;
	if (ft_strcmp(tabcmd[0], "ls") == 0)
		return;
	if (ft_strcmp(tabcmd[0], "pwd") == 0)
		return;
	if (ft_strcmp(tabcmd[0], "put") == 0)
		return;
	if (ft_strcmp(tabcmd[0], "get") == 0)
		return;
	freetab(tabcmd);
}
