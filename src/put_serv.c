#include <ft_p.h>

int		get_fsize(t_serv clt)
{
	int		r;
	char	buf[1024];
	int		size;

	r = read(clt.cs, buf, 1023);
	if (r > 0)
	{
		buf[r] = '\0';
		size = ft_atoi(buf);
		printf("buf : %s\n", buf);
	}
	else
		size = -1;
	return (size);
}

void	get_fdata(t_serv clt, int size, int fd)
{
	int		r;
	char	buf[size];

	r = read(clt.cs, buf, size);
	if (r > 0)
	{
		write(fd, buf, size);
	}
}

char	*getname(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, '/');
	while(tab[i])
		i++;
	return (tab[i - 1]);
}

void	put_serv(char *str, t_serv clt)
{
	int				size;
	int				fd;
	char			*name;

	name = getname(str);
	printf("reception de fichier : %s \n", name);
	size = get_fsize(clt);
	printf("%d\n", size);
	if (size == -1)
		return ;
	fd = open(name, O_CREAT|O_RDWR, 0777);
	get_fdata(clt, size, fd);
	printf("Done\n");
}
