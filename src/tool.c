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

char *ft_itoa(int n)
{
	char *s;

	s = malloc(100);
	s += 100;
	*s = 0;
	while (1)
	{
		s--;
		*s = n % 10 + '0';
		n = n / 10;
		if (!n)
		break;
	}
	return (s);
}

int		forkexecv(char *path, char **in)
{
	pid_t	id;
	int		useless;

	id = fork();
	if (id == 0)
	{
		if (execv(path, in) == -1)
		{
			ft_putstr("sboub");
				exit(0);
		}
	}
	else
		wait(&useless);
	return (0);
}
