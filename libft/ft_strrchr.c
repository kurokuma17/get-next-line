/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:06:07 by trnguyen          #+#    #+#             */
/*   Updated: 2021/11/14 20:09:56 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	else
		return (last);
}
