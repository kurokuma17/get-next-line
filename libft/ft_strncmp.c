/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:01:23 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/12 22:55:04 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n)
	{
		while (s1[i] && i < n - 1 && s1[i] == s2[i])
			i++;
		return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
	}
	return (0);
}
