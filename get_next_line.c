/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:38:12 by trnguyen          #+#    #+#             */
/*   Updated: 2022/01/17 15:29:20 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(const int fd, char **line, char **remain)
{
	char	*temp;
	size_t	len;

	len = ft_strcspn(remain[fd], "\n");
	if (remain[fd][len] == '\n')
	{
		*line = ft_strndup(remain[fd], len);
		if (!*line)
			return (-1);
		temp = ft_strdup(remain[fd] + len + 1);
		if (!temp)
			return (-1);
		free(remain[fd]);
		remain[fd] = temp;
		if (remain[fd][0] == '\0')
			ft_strdel(&remain[fd]);
	}
	else if (remain[fd][len] == '\0')
	{
		*line = ft_strdup(remain[fd]);
		ft_strdel(&remain[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*remain[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		bytes;

	if (fd < 0 || !line || fd >= MAX_FD || BUFF_SIZE <= 0)
		return (-1);
	bytes = read(fd, buff, BUFF_SIZE);
	while (bytes > 0)
	{
		buff[bytes] = '\0';
		if (remain[fd] == NULL)
			remain[fd] = ft_strnew(1);
		temp = ft_strjoin(remain[fd], buff);
		free(remain[fd]);
		remain[fd] = temp;
		if (ft_strchr(remain[fd], '\n'))
			break ;
		bytes = read(fd, buff, BUFF_SIZE);
	}
	if (bytes < 0)
		return (-1);
	if ((bytes == 0 && remain[fd] == NULL) || remain[fd][0] == '\0')
		return (0);
	return (get_line(fd, line, remain));
}
