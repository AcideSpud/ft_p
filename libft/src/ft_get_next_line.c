/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:25:27 by ajulien           #+#    #+#             */
/*   Updated: 2015/02/23 19:09:41 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin2(char const *sstatic, char const *tmp)
{
	char	*new;
	size_t	lens;

	if (!sstatic)
	{
		new = ft_strdup(tmp);
		return (new);
	}
	lens = ft_strlen(sstatic);
	if (!(new = ft_strnew(lens + ft_strlen(tmp))))
		return (NULL);
	ft_strcpy(new, sstatic);
	ft_strcpy((new + lens), tmp);
	return (new);
}

static int	ft_strcatbuff(int const fd, char **sstatic)
{
	char	*tmp;
	int		retread;

	if (!(tmp = ft_strnew(BUFF_SIZE_GNL)))
		return (-1);
	retread = read(fd, (void *)tmp, BUFF_SIZE_GNL);
	*sstatic = ft_strjoin2(*sstatic, tmp);
	free(tmp);
	tmp = NULL;
	return (retread);
}

static char	*ft_setx2(char **ptrn, char **sstatic)
{
	char	*line;
	size_t	nlen;

	nlen = ft_strlen(*sstatic) - ft_strlen(*ptrn);
	line = ft_strndup(*sstatic, nlen);
	*sstatic = ft_strdup(*ptrn + 1);
	return (line);
}

static int	ft_setx2ret0(char **sstatic, char **line)
{
	if (**sstatic)
	{
		*line = ft_strdup(*sstatic);
		ft_strclr(*sstatic);
		return (1);
	}
	else
		return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char *sstatic = "\0";
	char		*ptrn;
	int			ret;

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	while (ret > 0 && !(ptrn = ft_strchr(sstatic, '\n')))
		ret = ft_strcatbuff(fd, &sstatic);
	if ((ptrn = ft_strchr(sstatic, '\n')))
	{
		if (!(*line = ft_setx2(&ptrn, &sstatic)))
			return (-1);
		return (1);
	}
	if (ret == 0)
		return (ft_setx2ret0(&sstatic, line));
	else
		return (-1);
}
