#include <ft_p.h>

void	pwd_serv(char **tab, t_serv clt)
{
	char	*pwd;

	if (tablen(tab) != 1)
	{
		write(clt.cs,
		"ERROR : Only pwd without argument is supported by the serveur.\n", 63);
		return ;
	}
	else
	{
		pwd = getcwd(NULL, 0);
		write(clt.cs, pwd, ft_strlen(pwd));
		write(clt.cs, "\n", 1);
		free(pwd);
		pwd = NULL;
		return ;
	}
}

int		check_quit(char **tab, t_serv clt)
{
	if (tablen(tab) == 1)
	{
		write(clt.cs, "SUCCES\n", 7);
		return (0);
	}
	else
	{
		write(clt.cs, "ERROR : quit doesn't take any argument.\n", 40);
		return (-1);
	}
}

void	hub_serv(char *str, t_serv clt)
{
	char	**tabcmd;

	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	tabcmd = ft_strsplit(str, ' ');
	if (ft_strcmp(tabcmd[0], "quit") == 0)
	{
		if (check_quit(tabcmd, clt) == 0)
			close_socket(clt);
	}
	else if (ft_strcmp(tabcmd[0], "cd") == 0)
		serv_cd(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "ls") == 0)
		serv_ls(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "pwd") == 0)
		pwd_serv(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "put") == 0)
		put_serv(tabcmd[1], clt);
	else if (ft_strcmp(tabcmd[0], "get") == 0)
		return ;
	else
		write(clt.cs, "Command unknown to serveur.\n", 28);
	freetab(tabcmd);
}
