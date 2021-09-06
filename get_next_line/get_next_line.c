/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:28:16 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/06 18:28:17 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_free_null(char **line, int res, char **remainder)
{
	if (*remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
	if ((res == 0 && !**line) || res < 0)
	{
		free(*line);
		*line = NULL;
	}
	return (res);
}

char	*check_remainder(char **remainder, char **line)
{
	char	*tmp;

	if (*remainder)
	{
		if (!gnl_strdup(*remainder, line))
			return (NULL);
		tmp = gnl_strchr(*line, '\n');
		if (tmp)
			*++tmp = '\0';
		tmp = gnl_strchr(*remainder, '\n');
		if (tmp)
			gnl_strdup(++tmp, remainder);
		else if (!tmp && *remainder)
			my_free_null(line, 1, remainder);
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		if (!*line)
			return (NULL);
		**line = '\0';
	}
	return (*line);
}

int	get_line(int fd, char **line, char **remainder)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			res;

	if (check_remainder(remainder, line) == NULL)
		return (-1);
	while (1)
	{
		if (*remainder)
			return (gnl_strlen(*line));
		res = read(fd, buf, BUFFER_SIZE);
		if (res <= 0)
			return (my_free_null(line, res, remainder));
		buf[res] = '\0';
		tmp = gnl_strchr(buf, '\n');
		if (tmp)
		{
			if (!gnl_strdup(++tmp, remainder))
				return (-1);
			*tmp = '\0';
		}
		*line = gnl_strjoin(line, buf, gnl_strlen(*line), gnl_strlen(buf));
	}
}

t_gnl	*new_list(int fd, t_gnl *tmp)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->res = 0;
	new->remainder = NULL;
	new->prev = tmp;
	new->next = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_gnl	*data;
	t_gnl			*tmp;
	char			*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!data)
		data = new_list(fd, NULL);
	if (!data)
		return (NULL);
	tmp = data;
	while (tmp->fd != fd)
	{
		if (!tmp->next)
		{
			tmp->next = new_list(fd, tmp);
			if (!tmp->next)
				return (NULL);
		}
		tmp = tmp->next;
	}
	if (get_line(tmp->fd, &line, &tmp->remainder) <= 0)
		node_delete(&data, tmp);
	return (line);
}
