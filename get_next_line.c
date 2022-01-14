/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:38:12 by trnguyen          #+#    #+#             */
/*   Updated: 2022/01/13 01:59:11 by trnguyen         ###   ########.fr       */
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
		if (ft_strchr(buff, '\n'))
			break ;
		bytes = read(fd, buff, BUFF_SIZE);
	}
	if (bytes < 0)
	{
		ft_memdel((void **)remain);
		return (-1);
	}
	if ((bytes == 0 && remain[fd] == NULL) || remain[fd][0] == '\0')
	{
		ft_memdel((void **)remain);
		return (0);
	}
	return (get_line(fd, line, remain));
}

// static void	add_to_line(char **line, char **cache)
// {
// 	char	*newline;
// 	char	*temp;

// 	newline = ft_strchr(*cache, '\n');
// 	if (!newline)
// 	{
// 		*line = ft_strdup(*cache);
// 		ft_strdel(cache);
// 	}
// 	else
// 	{
// 		*line = ft_strsub(*cache, 0, (newline - *cache));
// 		temp = ft_strdup(newline + 1);
// 		free(*cache);
// 		*cache = temp;
// 		if ((*cache)[0] == '\0')
// 			ft_strdel(cache);
// 	}
// }

// static char	*buff_to_cache(char *buff, char *cache)
// {
// 	char	*temp;

// 	if (!cache)
// 		cache = ft_strnew(1);
// 	temp = ft_strjoin(cache, buff);
// 	free(cache);
// 	return (temp);
// }

// int	get_next_line(const int fd, char **line)
// {
// 	static char	*caches[MAX_FD + 1];
// 	char		buff[BUFF_SIZE + 1];
// 	ssize_t		bytes_read;

// 	if (fd < 0 || !line || fd > MAX_FD)
// 		return (-1);
// 	bytes_read = 1;
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = read(fd, &buff, BUFF_SIZE);
// 		if (bytes_read < 0)
// 			break ;
// 		buff[bytes_read] = '\0';
// 		caches[fd] = buff_to_cache(buff, caches[fd]);
// 		if (caches[fd][0] == '\0')
// 			ft_strdel(&(caches[fd]));
// 		if (ft_strchr(buff, '\n'))
// 			break ;
// 	}
// 	if (bytes_read < 0)
// 		return (-1);
// 	if (bytes_read == 0 && !caches[fd])
// 		return (0);
// 	add_to_line(line, &(caches[fd]));
// 	return (1);
// }


// static int			gnl_verify_line(char **remain, char **line)
// {
// 	char			*tmp_remain;
// 	char			*strchr_remain;
// 	int				i;

// 	i = 0;
// 	strchr_remain = *remain;
// 	while (strchr_remain[i] != '\n')
// 		if (!strchr_remain[i++])
// 			return (0);
// 	tmp_remain = &strchr_remain[i];
// 	*tmp_remain = '\0';
// 	*line = ft_strdup(*remain);
// 	*remain = ft_strdup(tmp_remain + 1);
// 	return (1);
// }


// static	int			gnl_read_file(int fd, char *temp, char **remain, char **line)
// {
// 	int				ret;
// 	char			*tmp_remain;

// 	while ((ret = read(fd, temp, BUFF_SIZE)) > 0)
// 	{
// 		temp[ret] = '\0';
// 		if (*remain)
// 		{
// 			tmp_remain = *remain;
// 			*remain = ft_strjoin(tmp_remain, temp);
// 			free(tmp_remain);
// 			tmp_remain = NULL;
// 		}
// 		else
// 			*remain = ft_strdup(temp);
// 		if (gnl_verify_line(remain, line))
// 			break ;
// 	}
// 	return (RET_VALUE(ret));
// }


// int					get_next_line(int const fd, char **line)
// {
// 	static char		*remain[MAX_FD];
// 	char			*temp;
// 	int				ret;
// 	int				i;

// 	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, remain[fd], 0) < 0) \
// 		|| !(temp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
// 		return (-1);
// 	if (remain[fd])
// 		if (gnl_verify_line(&remain[fd], line))
// 			return (1);
// 	i = 0;
// 	while (i < BUFF_SIZE)
// 		temp[i++] = '\0';
// 	ret = gnl_read_file(fd, temp, &remain[fd], line);
// 	free(temp);
// 	if (ret != 0 || remain[fd] == NULL || remain[fd][0] == '\0')
// 	{
// 		if (!ret && *line)
// 			*line = NULL;
// 		return (ret);
// 	}
// 	*line = remain[fd];
// 	remain[fd] = NULL;
// 	return (1);
// }

