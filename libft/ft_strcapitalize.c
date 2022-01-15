/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:54:09 by trnguyen          #+#    #+#             */
/*   Updated: 2022/01/15 19:08:58 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	str = ft_strlowcase(str);
	while (str[i])
	{
		if (ft_islower(str[i]))
		{
			if (j == 1)
				str[i] = ft_toupper(str[i]);
			j = 0;
		}
		else if (ft_isdigit(str[i]))
			j = 0;
		else
			j = 1;
		i++;
	}
	return (str);
}
