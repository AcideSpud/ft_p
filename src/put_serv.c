#include <ft_p.h>

int		get_fsize(t_serv clt)
{
	int		r;
	char	*buf[1024];
	int		size;

	r = read(clt.cs, buf, 1023);
	if (r == 0)
		return (0);
	if (r > 0)
	{
		buf[r] = '\0';
		size = ft_atoi((char *)buf);
	}
	return (size);
}

char	*get_fdata(t_serv clt, int size)
{
	int		r;
	char	*buf[size + 1];
	char	*str;

	r = read(clt.cs, buf, size);
	if (r == 0)
		return (NULL);
	if (r > 0)
	{
		buf[r] = '\0';
		str = ft_strdup((char *)buf);
	}
	return (str);

}

void	error_put(t_serv clt)
{
	write(clt.cs, "error_size", 10);
}

void	put_serv(char *str, t_serv clt)
{
	unsigned int	size;
	char 			*data;
	int				fd;

	write(clt.cs, "ok", 2);
	size = get_fsize(clt);
	if (size == 0)
	{
		error_put(clt);
		return ;
	}
	data = get_fdata(clt, size);
	fd = open(str, O_CREAT|O_RDWR, 0777);
	write(fd, data, size);
	write(clt.cs, "recu", 4);
}
