#include <ft_p.h>

void	serv_ls(char **tab, t_serv clt)
{
	(void)clt;

	forkexecv("/bin/ls", tab);
	//dup2(1, clt.cs);
}

void	serv_cd(char **tab, t_serv clt)
{
	char *str1;
	char *str2;

	if (tablen(tab) == 1)
	{
		chdir(clt.home);
		write(clt.cs, "0", 1);
	}
	else
	{
		str1 = getcwd(NULL, 0);
		if (chdir(tab[1]) == -1)
			write(clt.cs, "1", 1);
		else
		{
			str2 = getcwd(NULL, 0);
			if (ft_strlen(str2) < ft_strlen(clt.home))
			{
				chdir(str1);
				write(clt.cs, "1", 1);
			}
			else
				write(clt.cs, "0", 1);
			free(str2);
		}
		free(str1);
	}
}