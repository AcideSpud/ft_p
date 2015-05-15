#include <ft_p.h>

int		create_server(int	port)
{
	t_serv		clt;
	if(!(clt.proto = getprotobyname("tcp")))
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
	if(r > 0)
	{
		buf[r] = '\0';
		printf("receive %d bytes: [%s] \n", r, buf);
		if (ft_strcmp("quit", buf))
			return (1);
	}
	return (0);
}

int		new_client(t_serv	clt)
{
	pid_t				p;

	p = fork();
	printf("New Client\n");
	if (p)
	{
		printf("parent\n");
		return (-1);
	}
	else if (!p)
	{
		while(1)
		{
			if (exec_client(clt) == 1)
			{
				printf("Un client est mort\n");
				close(clt.cs);
				return (-1);
			}
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_serv			clt;

	if (argc != 2)
		usage_serveur(argv[0]);
	clt.port = atoi(argv[1]);
	printf("port : %d \n", clt.port);
	clt.sock = create_server(clt.port);
	while((clt.cs = accept(clt.sock, (struct sockaddr*)&clt.csin, &clt.cslen)))
		if(new_client(clt) == -1)
			break;
	close(clt.sock);
	return (0);
}
