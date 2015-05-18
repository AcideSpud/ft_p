#include <ft_p.h>

char 	*join_string(char **tab)
{
	char	*s;
	char	*full;

	s = ft_strjoin(tab[0], " ");
	full = ft_strjoin(s, tab[1]);
	free(s);
	return (full);
}

char*		get_ssize(char **tab)
{
	struct	stat	s;
	int				size;
	int				fd;
	char			*it;

	if ((fd = open(tab[1], O_RDONLY)) == -1)
	{
		printf("erreur fichier non lisible\n");
		it = ft_itoa(-1);
		return (it);
	}
	fstat(fd, &s);
	size = s.st_size;
	it = ft_itoa(size);
	return (it);
}

void	send_data(t_client clt, char **tab)
{
	struct	stat	s;
	int				size;
	int				fd;
	char			*f;

	fd = open(tab[1], O_RDONLY);
	fstat(fd, &s);
	size = s.st_size;
	f = (char *)mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	write(clt.sock, f, size);
}

void	put_hub(char **tab, t_client clt)
{
	char	*st;
	char	buf[1024];
	int		r;
	char	*size;

	st = join_string(tab);
	write(clt.sock, st, ft_strlen(st));
	r = read(clt.sock, buf, 1023);
	buf[r] = '\0';
	if (ft_strcmp(buf, "ok") == 0)
		size = get_ssize(tab);
	else
		size = ft_itoa(-1);
	if (ft_strcmp(size ,"-1") != 0)
	{
		write(clt.sock, size, ft_strlen(size));
		send_data(clt, tab);
	}
}
