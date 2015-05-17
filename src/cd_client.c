#include <ft_p.h>

void	cd_hub(char **tab, char *str, t_client clt)
{
	int		r;
	char	buf[1024];

	if (tablen(tab) > 2)
		too_many_argument(tab[0]);
	else
	{
		write(clt.sock, str, ft_strlen(str));
		while(1)
		{
			r = read(clt.sock, buf, 1023);
			buf[r] = '\0';
			if (buf[0] == '1')
			{
				printf("ERROR : %s Request cannot be completed. \n",
				 str);
				break;
			}
			else if (buf[0] == '0')
			{
				ft_putstr("SUCCES \n");
				break;
			}
		}
	}
}
