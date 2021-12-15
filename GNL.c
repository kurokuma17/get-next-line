/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:51:28 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/15 20:20:39 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


//	int get_next_line(const int fd, char **line);
int main(void)
{
	int fd;
	char buff;
	//size_t lsize;
	fd = open("intro", O_RDONLY);
	printf("%d\n", fd);
	while (read(fd, &buff, 1) && buff != '\n')
		printf("%c", buff);
	//printf("%lu\n", strlen(buff));
	
}
