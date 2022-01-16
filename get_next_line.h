/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:38:51 by trnguyen          #+#    #+#             */
/*   Updated: 2022/01/16 15:00:07 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define MAX_FD 8192
# ifndef BUFF_SIZE
#  define BUFF_SIZE 32
# endif

int	get_next_line(const int fd, char **line);

#endif
