/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:34:16 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/12 20:37:12 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		if (((const unsigned char *)src)[i] == (unsigned char)c)
			return ((unsigned char *)dst + i + 1);
		i++;
	}
	return (0);
}
