#include <ft_p.h>

void	hub_client(char *str, t_client clt)
{
	char	**tabcmd;

	if (strlen(str) < 2)
		return ;
	tabcmd = ft_strsplit(str, ' ');
	if (ft_strcmp(tabcmd[0], "quit") == 0)
		quit_hub(str, clt);
	else if (ft_strcmp(tabcmd[0], "cd") == 0)
		cd_hub(str, clt);
	else if (ft_strcmp(tabcmd[0], "ls") == 0)
		ls_hub(str, clt);
	else if (ft_strcmp(tabcmd[0], "pwd") == 0)
		pwd_hub(str, clt);
	else if (ft_strcmp(tabcmd[0], "put") == 0)
		put_hub(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "get") == 0)
		get_hub(tabcmd, clt);
	else
		parse_error(tabcmd[0]);
	freetab(tabcmd);
}
