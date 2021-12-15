/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:52:05 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/12 21:28:05 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((const unsigned char)*s1 - (const unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((const unsigned char)*s1 - (const unsigned char)*s2);
}
