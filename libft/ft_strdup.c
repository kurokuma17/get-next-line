/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:05:08 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/12 21:40:23 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
