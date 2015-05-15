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

int		forkexecv(char *path, char **in)
{
	pid_t	id;
	int		useless;

	id = fork();
	if (id == 0)
		execv(path, in);
	else
		wait(&useless);
	return (0);
}
