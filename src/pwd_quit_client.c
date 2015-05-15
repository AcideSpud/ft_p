#include <ft_p.h>
void	pwd_hub(char **tab, t_client clt)
{
	(void)tab;
	(void)clt;

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
