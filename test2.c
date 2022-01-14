#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"
#include "libft/libft.h"

int main (int argc, char **argv)
{
	char	*buff;
	int		ret;
	int		fd = 0;
	int		line = 1;
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, line++, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of stdin\n");
		close(fd);
	}
	if (argc == 2)
	{
		int		temp;
		char *tempname = ft_strjoin(argv[1], ".test");
		temp = open(tempname, O_RDWR | O_CREAT | O_TRUNC);
		fd = open(argv[1], O_RDONLY);
		//fd = 42;
		ret = get_next_line(fd, &buff);
		ft_strdel(&tempname);
		while (ret > 0)
		{
			ft_putstr_fd(buff, temp);
			printf("[Return: %d] Line #%d: %s\n", ret, line++, buff);
			ft_strdel(&buff);
			if (ret > 0)
				ft_putchar_fd('\n',temp);
			ret = get_next_line(fd, &buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		close(fd);
		close(temp);
	}
}