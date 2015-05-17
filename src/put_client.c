#include <ft_p.h>

void	put_hub(char **tab, t_client clt)
{
	char	*s;

	s = ft_strjoin(tab[0], " ");
	s = ft_strjoin(s, tab[1]);
	write(clt.sock, s, ft_strlen(s));


	return;
}
