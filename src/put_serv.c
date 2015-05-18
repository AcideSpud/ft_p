#include <ft_p.h>

int		get_fsize(t_serv clt)
{
	int		r;
	char	buf[1024];
	int		size;

	r = read(clt.cs, buf, 1023);
	if (r == 0)
		return (0);
	if (r > 0)
	{
		buf[r] = '\0';
		size = ft_atoi(buf);
	}
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

void	error_put(t_serv clt)
{
	write(clt.cs, "error_size", 10);
}

void	put_serv(char *str, t_serv clt)
{
	unsigned int	size;
	int				fd;

	(void)str;
	printf("reception de fichier \n");
	write(clt.cs, "ok", 2);
	size = get_fsize(clt);
	fd = open("camarche", O_CREAT|O_RDWR, 0777);
	if (size == 0)
	{
		error_put(clt);
		return ;
	}
	get_fdata(clt, size, fd);
	printf("Done\n");
}
