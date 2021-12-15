/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:38:51 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 18:53:36 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 32
int get_next_line(const int fd, char **line);
#endif
