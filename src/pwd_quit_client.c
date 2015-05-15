#include <ft_p.h>
void	pwd_hub(char **tab, t_client clt)
{
	int		r;
	char	buf[1024];

	if (tablen(tab) != 1)
		too_many_argument(tab[0]);
	else
	{
		write(clt.sock, "pwd", 3);
		while(1)
		{
			r = read(clt.sock, buf, 1023);
			buf[r] = '\0';
			printf("%s\n", buf);
			if (r < 1024)
				break;
		}
	}
	return ;
}

void	quit_hub(char **tab, t_client clt)
{
	if (tablen(tab) != 1)
	{
		too_many_argument(tab[0]);
		return ;
	}
	else
	{
		write(clt.sock, "quit", 4);
		close(clt.sock);
		exit(0);
	}
}
