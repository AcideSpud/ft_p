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
	}
	else
		size = -1;
	printf("%d\n", size);
	return (size);
}

void	get_fdata(t_serv clt, int size, int fd)
{
	int		r;
	char	*buf;
	int		vef;

	vef = 0;
	buf = (char *)malloc(sizeof(char) * size);
	while (vef < size)
	{
		r = read(clt.cs, buf + vef, size - vef);
		vef += r;
	}
	write(fd, buf, size);
	free(buf);
	buf = NULL;
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

void	put_serv(char *str, t_serv clt)
{
	int				size;
	int				fd;
	char			*name;

	name = getname(str);
	printf("Trying to recieve file : %s \n", name);
	write(clt.cs, "ok\0", 3);
	size = get_fsize(clt);
	printf("%d\n", size);
	if (size == -1)
	{
		printf("ERROR\n");
		return ;
	}
	fd = open(name, O_CREAT | O_RDWR, 0777);
	get_fdata(clt, size, fd);
	close(fd);
	printf("SUCCES\n");
}
