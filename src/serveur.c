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

int		main(int argc, char **argv)
{
	char				buf[1024];
	t_serv			clt;
	int					r;

	if (argc != 2)
		usage_serveur(argv[0]);
	clt.port = atoi(argv[1]);
	printf("port : %d \n", clt.port);
	clt.sock = create_server(clt.port);
	clt.cs = accept(clt.sock, (struct sockaddr*)&clt.csin, &clt.cslen);
	r = read(clt.cs, buf, 1023);
	if (r > 0)
	{
		buf[r] = '\0';
		printf("received %d bytes: [%s]\n", r, buf);
	}
	close(clt.sock);
	close(clt.cs);
	return (0);
}
