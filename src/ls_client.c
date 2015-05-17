#include <ft_p.h>

void	ls_hub(char **tab, char *str, t_client clt)
{
	//int		r;
	//char 	buf[1024];

	if (tablen(tab) > 3)
		too_many_argument(tab[0]);
	else
	{
		write(clt.sock, str, ft_strlen(str));
		/*while(1)
		{
			r = read(clt.sock, buf, 1023);
			buf[r] = '\0';
			printf("%s\n", buf);
			if (r < 1024)
				break;
		}*/
	}
	return ;
}
