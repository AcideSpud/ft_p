#include <ft_p.h>

int		create_client(char *addr, int port)
{
	t_client	clt;

	if (!(clt.proto = getprotobyname("tcp")))
		return (-1);
	clt.sock = socket(PF_INET, SOCK_STREAM, clt.proto->p_proto);
	clt.sin.sin_family = AF_INET;
	clt.sin.sin_port = htons(port);
	clt.sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(clt.sock, (const struct sockaddr *)&clt.sin,
									sizeof(clt.sin)) == -1)
	{
		printf("connect error\n");
		exit(2);
	}
	return (clt.sock);
}

int		main(int argc, char **argv)
{
	t_client	clt;
	char		*line;

	if (argc != 3)
		usage_client(argv[0]);
	clt.port = atoi(argv[2]);
	printf("port : %d \n", clt.port);
	if (ft_strcmp(argv[1], "localhost") == 0)
		clt.sock = create_client("127.0.0.1", clt.port);
	else
		clt.sock = create_client(argv[1], clt.port);
	while (1)
	{
		ft_putstr("Plait-il ?>");
		get_next_line(0, &line);
		hub_client(line, clt);
		free(line);
		line = NULL;
	}
	close(clt.sock);
	return (0);
}
