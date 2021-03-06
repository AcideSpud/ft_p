#include <ft_p.h>

int		create_server(int port)
{
	t_serv	clt;

	if (!(clt.proto = getprotobyname("tcp")))
		return (-1);
	clt.sock = socket(PF_INET, SOCK_STREAM, clt.proto->p_proto);
	clt.sin.sin_family = AF_INET;
	clt.sin.sin_port = htons(port);
	clt.sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(clt.sock, (const struct sockaddr *)&clt.sin, sizeof(clt.sin));
	listen(clt.sock, 42);
	return (clt.sock);
}

int		exec_client(t_serv clt)
{
	int		r;
	char	buf[1024];

	r = read(clt.cs, buf, 1023);
	if (r == 0)
		return (1);
	if (r > 0)
	{
		buf[r] = '\0';
		printf("Received %d bytes.\nMessage : %s \n", r, buf);
		hub_serv(buf, clt);
	}
	return (0);
}

int		new_client(t_serv clt)
{
	pid_t	p;

	p = fork();
	if (p)
		return (0);
	else if (!p)
		while (1)
		{
			if (exec_client(clt) == 1)
				exit(1);
		}
	return (0);
}

int		checkargv(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		return (-1);
	if (ft_strlen(argv[1]) != 4)
		return (-1);
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_serv	clt;

	if (checkargv(argc, argv) == -1)
		usage_serveur(argv[0]);
	clt.port = atoi(argv[1]);
	printf("port : %d \n", clt.port);
	clt.sock = create_server(clt.port);
	clt.home = getcwd(NULL, 0);
	while (1)
	{
		if ((clt.cs = accept(clt.sock,
				(struct sockaddr*)&clt.csin, &clt.cslen)))
			if (new_client(clt) == -1)
				break ;
	}
	close(clt.sock);
	return (0);
}
