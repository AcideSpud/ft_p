#include <ft_p.h>

char	*get_csize(char *str)
{
	struct stat		s;
	int				size;
	int				fd;
	char			*it;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		printf("ERROR : File cannot be accessed.\n");
		return ("-1");
	}
	fstat(fd, &s);
	if (!(S_ISREG(s.st_mode)))
	{
		printf("ERROR : File cannot be accessed.\n");
		return ("-1");
	}
	size = s.st_size;
	it = ft_itoa(size);
	return (it);
}

void	send_data(t_serv clt, char *str)
{
	struct stat		s;
	int				size;
	int				fd;
	char			*f;

	fd = open(str, O_RDONLY);
	fstat(fd, &s);
	size = s.st_size;
	f = (char *)mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	write(clt.cs, f, size);
}

char	*getiname(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, '/');
	while (tab[i])
		i++;
	return (tab[i - 1]);
}

void	get_serv(char *str, t_serv clt)
{
	char	*size;
	char	*name;

	name = getiname(str);
	printf("File sent : %s.\n", name);
	size = get_csize(name);
	write(clt.cs, size, ft_strlen(size));
	if (ft_strcmp(size, "-1") != 0)
		send_data(clt, str);
}
