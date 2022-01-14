/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:38:51 by trnguyen          #+#    #+#             */
/*   Updated: 2022/01/13 13:54:48 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
//# define BUFF_SIZE 8
# define MAX_FD 8192
# define RET_VALUE(ret)	ret > 0 ? 1 : ret

int	get_next_line(const int fd, char **line);

#endif
