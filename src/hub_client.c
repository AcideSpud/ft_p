#include <ft_p.h>

void		freetab(char **abc)
{
	int		i;

	i = 0;
	while (abc[i] != NULL)
	{
		free(abc[i]);
		abc[i] = NULL;
		i++;
	}
	free(abc[i]);
	abc[i] = NULL;
	free(abc);
}

int		tablen(char **abc)
{
	int		i;

	i = 0;
	while (abc[i] != NULL)
		i++;
	return(i);
}

void	hub_client(char *str, t_client clt)
{
	char	**tabcmd;

	tabcmd = ft_strsplit(str, ' ');
	if (ft_strcmp(tabcmd[0], "quit"))
		quit_hub(tabcmd, clt);
	if (ft_strcmp(tabcmd[0], "cd"))
		cd_hub(tabcmd, clt);
	if (ft_strcmp(tabcmd[0], "ls"))
		ls_hub(tabcmd, clt);
	if (ft_strcmp(tabcmd[0], "pwd"))
		pwd_hub(tabcmd, clt);
	if (ft_strcmp(tabcmd[0], "put"))
		put_hub(tabcmd, clt);
	if (ft_strcmp(tabcmd[0], "get"))
		get_hub(tabcmd, clt);
	else
		parse_error(tabcmd[0]);
	freetab(tabcmd);
}
