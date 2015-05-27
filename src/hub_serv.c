#include <ft_p.h>

void	pwd_serv(char **tab, t_serv clt)
{
	char	*pwd;
	char	*ret;

	if (tablen(tab) != 1)
	{
		write(clt.cs,
		"ERROR : Only pwd without argument is supported by the serveur.\n", 63);
		return ;
	}
	else
	{
		pwd = getcwd(NULL, 0);
		ret = ft_strjoin(pwd, "\n");
		write(clt.cs, ret, ft_strlen(ret));
		// free(pwd);
		// pwd = NULL;
		// free(ret);
		// ret = NULL;
		return ;
	}
}

void	check_quit(char **tab, t_serv clt)
{
	if (tablen(tab) == 1)
	{
		write(clt.cs, "SUCCES\n", 7);
		close_socket(clt);
	}
	else
		write(clt.cs, "ERROR : quit doesn't take any argument.\n", 40);
}

void	hub_serv(char *str, t_serv clt)
{
	char	**tabcmd;

	if (strlen(str) < 2)
		return ;
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	tabcmd = ft_strsplit(str, ' ');
	if (ft_strcmp(tabcmd[0], "quit") == 0)
		check_quit(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "cd") == 0)
		serv_cd(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "ls") == 0)
		serv_ls(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "pwd") == 0)
		pwd_serv(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "put") == 0)
		put_serv(tabcmd[1], clt);
	else if (ft_strcmp(tabcmd[0], "get") == 0)
		get_serv(tabcmd[1], clt);
	else
		write(clt.cs, "Command unknown to serveur.\n", 28);
	freetab(tabcmd);
}
