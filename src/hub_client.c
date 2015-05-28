#include <ft_p.h>

void	lls(char **tab)
{
	int		id;

	id = fork();
	if (id == 0)
		execv("/bin/ls", tab);
	else
		wait4(id, 0, 0, 0);
}

void	lcd(char **tab, t_client clt)
{
	if (tablen(tab) == 1)
	{
		chdir(clt.home);
		printf("SUCCES\n");
	}
	else if (tablen(tab) > 2)
		printf("ERROR : Too many arguments for lcd.\n");
	else
	{
		if (chdir(tab[1]) == -1)
			printf("ERROR : Directory cannot be accessed.\n");
		else
			printf("SUCCES\n");
	}
}

void	hub_client2(char **tabcmd, t_client clt)
{
	if (ft_strcmp(tabcmd[0], "lls") == 0)
		lls(tabcmd);
	else if (ft_strcmp(tabcmd[0], "lpwd") == 0)
		ft_putendl(getcwd(NULL, 0));
	else if (ft_strcmp(tabcmd[0], "lcd") == 0)
		lcd(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "put") == 0)
		put_hub(tabcmd, clt);
	else if (ft_strcmp(tabcmd[0], "get") == 0)
		get_hub(tabcmd, clt);
	else
		parse_error(tabcmd[0]);
}

char	*tabtosp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 9)
			str[i] = 32;
		i++;
	}
	return (str);
}

void	hub_client(char *str, t_client clt)
{
	char	**tabcmd;

	str = tabtosp(str);
	tabcmd = ft_strsplit(str, ' ');
	if (ft_strcmp(tabcmd[0], "quit") == 0)
		quit_hub(str, clt);
	else if (ft_strcmp(tabcmd[0], "cd") == 0)
		cd_hub(str, clt);
	else if (ft_strcmp(tabcmd[0], "ls") == 0)
		ls_hub(str, clt);
	else if (ft_strcmp(tabcmd[0], "pwd") == 0)
		pwd_hub(str, clt);
	else
		hub_client2(tabcmd, clt);
	freetab(tabcmd);
}
