#include <ft_p.h>

void	pwd_serv(t_serv clt)
{
	char	*pwd;
	(void)clt;

	pwd = getcwd(NULL, 0);
	write(clt.cs, pwd, ft_strlen(pwd));
	free(pwd);
	pwd = NULL;
	return;
}

void	hub_serv(char *str, t_serv clt)
{
	char	**tabcmd;

	tabcmd = ft_strsplit(str, ' ');
	if (ft_strcmp(tabcmd[0], "quit") == 0)
		close_socket(clt);
	if (ft_strcmp(tabcmd[0], "cd") == 0)
		serv_cd(tabcmd, clt);
	if (ft_strcmp(tabcmd[0], "ls") == 0)
		serv_ls(tabcmd, clt);
	if (ft_strcmp(tabcmd[0], "pwd") == 0)
		pwd_serv(clt);
	if (ft_strcmp(tabcmd[0], "put") == 0)
		return;
	if (ft_strcmp(tabcmd[0], "get") == 0)
		return;
	freetab(tabcmd);
}
