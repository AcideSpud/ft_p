#include <ft_p.h>

void	freetab(char **abc)
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
	abc = NULL;
}

int		tablen(char **abc)
{
	int		i;

	i = 0;
	while (abc[i] != NULL)
		i++;
	return (i);
}

char	*ft_itoa(int n)
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
			break ;
	}
	return (s);
}
