#include <ft_p.h>

int		get_fsize(t_client clt)
{
	int		r;
	char	buf[1024];
	int		size;

	r = read(clt.sock, buf, 1023);
	if (r >= 0)
	{
		buf[r] = '\0';
		size = ft_atoi(buf);
	}
	else
		size = -1;
	return (size);
}

char	*join_istring(char **tab)
{
	char	*s;
	char	*full;

	s = ft_strjoin(tab[0], " ");
	full = ft_strjoin(s, tab[1]);
	free(s);
	return (full);
}

void	get_data(t_client clt, int size, int fd)
{
	int		r;
	char	buf[size];

	r = read(clt.sock, buf, size);
	if (r >= 0)
		write(fd, buf, size);
}

char	*getname(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, '/');
	while (tab[i])
		i++;
	return (tab[i - 1]);
}

void	get_hub(char **tab, t_client clt)
{
	int		size;
	int		fd;
	char	*name;
	char	*full;

	full = join_istring(tab);
	write(clt.sock, full, ft_strlen(full));
	name = getname(tab[1]);
	printf("File to reach : %s \n", name);
	size = get_fsize(clt);
	if (size == -1)
	{
		printf("ERROR : File cannot be accessed.\n");
		return ;
	}
	fd = open(name, O_CREAT | O_RDWR, 0777);
	get_data(clt, size, fd);
	close(fd);
	printf("SUCCES\n");
}
