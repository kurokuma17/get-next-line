#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "libft/libft.h"
#include "get_next_line.h"
#define MAX_FD 8192


int			get_next_line(const int fd, char **line)
{
	static char	*remain[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	char		*temp2;
	ssize_t		bytes;
	size_t		len;

	if (fd < 0 || !line || fd >= MAX_FD || BUFF_SIZE <= 0)
		return (-1);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (remain[fd] == NULL)
			remain[fd] = ft_strnew(1);
		temp = ft_strjoin(remain[fd], buff);
		free(remain[fd]);
		remain[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (bytes < 0)
		return (-1);
	if ((bytes == 0 && remain[fd] == NULL) || remain[fd][0] == '\0')
		return (0);
	len = ft_strcspn(remain[fd], "\n");
	if (remain[fd][len] == '\n')
	{
		*line = ft_strndup(remain[fd], len);
		if (!*line)
			return (-1);
		temp2 = ft_strdup(remain[fd] + len + 1);
		if (!temp2)
			return (-1);
		free(remain[fd]);
		remain[fd] = temp2;
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

// int	get_next_line(const int fd, char **line)
// {
// 	static char *remain[MAX_FD + 1];
// 	char	bufff[BUFfF_SIZE + 1];
// 	char	*temp;
// 	ssize_t	nbyte;
// 	if (fd < 0 || !line || fd >= MAX_FD || BUFfF_SIZE <= 0)
// 		return (-1);
// 	//if (!remain[fd])
// 	//	remain[fd] = ft_strnew(1);
// 	nbyte = read(fd, bufff, BUFfF_SIZE);
// 	while (nbyte > 0)
// 	{
// 		bufff[nbyte] = '\0';
// 	//	if (!remain[fd])
// 	//		remain[fd] = ft_strnew(1);

// 		*line = ft_strndup(bufff, ft_strcspn(bufff, "\n"));
// 		temp = ft_strjoin(remain[fd], bufff);
// 		free(remain[fd]);
// 		remain[fd] = temp;
// 	//	remain[fd] = ft_strdup(bufff + ft_strcspn(bufff, "\n"));
// 		if (ft_strchr(bufff, '\n'))
// 			break;
// 		nbyte = read(fd, bufff, BUFfF_SIZE);
// 	}
// 	//printf("BUFfF%sBUFfF\n", bufff);
// 	//printf("LINE%sLINE\n", *line);
// 	return (1);
// }

int	main(void)
{
	int fd = open("intro", O_RDONLY);
	char *line;

	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);

}