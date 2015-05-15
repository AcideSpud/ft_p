#include <ft_p.h>

void	usage_client(char *str)
{
	printf("Usage: %s <addr> <port>\n", str);
	exit(-1);
}

void	parse_error(char *str)
{
	printf("%s : Command not found. \n", str);
}

void	too_many_argument(char *str)
{
	printf("%s : Too many arguments. \n", str);
}
