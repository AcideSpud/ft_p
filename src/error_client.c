#include <ft_p.h>

void	usage_client(char *str)
{
	printf("Usage: %s <addr> <port>\n", str);
	exit(-1);
}

void	parse_error(char *str)
{
	printf("ERROR : [%s] command not found. \n", str);
}
