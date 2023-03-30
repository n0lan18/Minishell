/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:50:42 by nleggeri          #+#    #+#             */
/*   Updated: 2023/01/17 14:03:09 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*get_next(char *line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == 1)
		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*tmp == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	line[i + 1] = '\0';
	return (tmp);
}

static char	*read_tmp(int fd, char *buf, char *tmp)
{
	int		ret;
	char	*stash;

	ret = 1;
	while (ret != '\0')
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
			break ;
		buf[ret] = '\0';
		if (!tmp)
			tmp = ft_strdup("");
		stash = tmp;
		tmp = ft_strjoin(stash, buf);
		free(stash);
		stash = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (tmp)
			free(tmp);
		tmp = NULL;
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_tmp(fd, buf, tmp);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	tmp = get_next(line);
	return (line);
}
