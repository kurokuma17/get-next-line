/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:35:21 by trnguyen          #+#    #+#             */
/*   Updated: 2021/11/26 15:21:08 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	i;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	i = 0;
	if (dstsize < dstlen)
		res = dstsize + ft_strlen(src);
	else
		res = dstlen + ft_strlen(src);
	while (dstlen + i + 1 < dstsize && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (res);
}
