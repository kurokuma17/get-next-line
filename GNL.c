/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:51:28 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/23 13:40:07 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "libft/libft.h"
#include "get_next_line.h"
//# define BUFF_SIZE 3



//
// char changechar(int i) // testing static var
// {
// 	static char c = 'a';
// 	c = c + 1;
// 	printf("%d", i);
// 	return (c);
// }
//int get_next_line(const int fd, char **line);

size_t	ft_strclen(char	*str, char c)
{
	size_t	len;

	len = 0;
	if (str)
	{
		while (str[len] && str[len] != c)
			len++;
	}
	return(len);
}
// successfully read 1 line byte by byte, no freeing yet, no segfault regardless off bufsize
char	*readline(const int fd, char *line)
{
	char	buff;
	int		i;
	i = 0;
	line = ft_strnew(BUFF_SIZE);
	while (read(fd, &buff, 1) && buff != '\n')
	{
		if (buff == '\0')
			return (0);
		line[i] = buff;
		i++;
	}
	return (line);
}
int main()
{
	// read 1 line
	int		fd = open("intro", O_RDONLY);
	// char	*line = ft_strnew(BUFF_SIZE);
	// char	buff;
	// int i = 0;
	// while (read(fd, &buff, 1) && buff != '\n')
	// {
	// 	line[i] = buff;
	// 	i++;
	// }
	char **lines = (char **)malloc(sizeof(char*) * 20); //mallocate array of 20 strings
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	*lines = readline(fd, *lines);
	printf("%s\n", *lines);
	//lines++;
}
