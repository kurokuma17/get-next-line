/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:03:08 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/13 17:56:02 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
