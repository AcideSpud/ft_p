#include <ft_p.h>

void	pwd_hub(char *str, t_client clt)
{
	int		r;
	char	buf[1024];

	write(clt.sock, str, ft_strlen(str));
	r = read(clt.sock, buf, 1023);
	buf[r] = '\0';
	ft_putstr(buf);
	return ;
}

void	cd_hub(char *str, t_client clt)
{
	int		r;
	char	buf[1024];

	write(clt.sock, str, ft_strlen(str));
	r = read(clt.sock, buf, 1023);
	buf[r] = '\0';
	ft_putstr(buf);
	return ;
}

void	ls_hub(char *str, t_client clt)
{
	int		r;
	char	buf[1024];

	write(clt.sock, str, ft_strlen(str));
	while (1)
	{
		r = read(clt.sock, buf, 1023);
		buf[r] = '\0';
		ft_putstr(buf);
		if (r < 1023)
			break ;
	}
	return ;
}

void	quit_hub(char *str, t_client clt)
{
	int		r;
	char	buf[1024];

	write(clt.sock, str, ft_strlen(str));
	r = read(clt.sock, buf, 1023);
	buf[r] = '\0';
	ft_putstr(buf);
	if (ft_strcmp(buf, "SUCCES") == 0)
		close(clt.sock);
	exit(0);
}
