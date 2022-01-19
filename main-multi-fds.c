#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

int main (int argc, char **argv)
{
	char	*buff;
	int		ret;
	int		fd1, fd2, fd3;
	int		line1=1, line2=1, line3 = 1;

	if (argc == 4)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 = open(argv[3], O_RDONLY);

		printf("\nRun test multiple fds tests on: \n%s\n%s\n%s\n\n", argv[1], argv[2], argv[3]);
		ret = get_next_line(fd1, &buff);
		printf("[Return: %d] Line #%d from fd #%d: %s\n", ret, line1++, fd1, buff);
		free(buff);
		
		ret = get_next_line(fd2, &buff);
		printf("[Return: %d] Line #%d from fd #%d: %s\n", ret, line2++, fd2, buff);
		free(buff);
	
		ret = get_next_line(fd1, &buff);
		printf("[Return: %d] Line #%d from fd #%d: %s\n", ret, line1++, fd1, buff);
		free(buff);
		
		ret = get_next_line(fd3, &buff);
		printf("[Return: %d] Line #%d from fd #%d: %s\n", ret, line3++, fd3, buff);
		free(buff);

		close(fd1);
		close(fd2);
		close(fd3);
		printf("\n");
		system("leaks test_gnl_multi | grep 'leaked'");
	}
}