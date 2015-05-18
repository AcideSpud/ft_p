#include <ft_p.h>

int		check_ls(char **tab)
{
	if (tablen(tab) > 1)
	{
		if (ft_strcmp(tab[1], "-l") == 0)
			return (0);
		else
			return (-1);
	}
	else
		return (0);
}
void	serv_ls(char **tab, t_serv clt)
{
	 if (check_ls(tab) == -1)
	{
		write(clt.cs,
			"ERROR : Only ls and ls -l are supportedby the serveur.\n", 56);
	}
	else
	{
		dup2(clt.cs, 1);
		forkexecv("/bin/ls", tab);
	}
	return ;
}

void	check_root_cd(t_serv clt, char *str1)
{
	char	*str2;

	str2 = getcwd(NULL, 0);
	if (ft_strlen(str2) < ft_strlen(clt.home))
	{
		chdir(str1);
		write(clt.cs,
			"ERROR : Directory is beyond serveur's root directory.\n", 54);
	}
	else
		write(clt.cs, "SUCCES\n", 7);
	free(str2);
	return ;
}

void	serv_cd(char **tab, t_serv clt)
{
	char	*str1;

	if (tablen(tab) == 1)
	{
		chdir(clt.home);
		write(clt.cs, "SUCCES\n", 7);
	}
	else if (tablen(tab) > 2)
		write(clt.cs, "ERROR : Too many arguments for cd.\n" , 35);
	else
	{
		str1 = getcwd(NULL, 0);
		if (chdir(tab[1]) == -1)
			write(clt.cs, "ERROR : Directory cannot be accessed.\n", 38);
		else
			check_root_cd(clt, str1);
		free(str1);
	}
	return ;
}
