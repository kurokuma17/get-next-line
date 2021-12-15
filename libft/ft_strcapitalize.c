/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:54:09 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 15:27:18 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "stdio.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i, j;
	i = 0;
	j = 1;
	str = ft_strlowcase(str);
	while (str[i])
	{
		if (ft_islower(str[i])) //(str[i] >= 'a' && str[i] <= 'z')
		{
			if (j == 1)
				str[i] = ft_toupper(str[i]);
			j = 0;
		}
		else if (ft_isdigit(str[i])) //(str[i] >= '0' && str[i] <= '9')
			j = 0;
		else
			j = 1;
		i++;
	}

	// {
	// 	while (!ft_isalnum(str[i]))
	// 		i++;
	// 	if (ft_isalnum(str[i]) && (!ft_isalnum(str[i-1]) || str[i - 1])
	// 	{
	// 		str[i] = ft_toupper(str[i]);
	// 		i++;
	// 	}
	// 	while (ft_isalnum(str[i]) && str[i])
	// 		i++;
	// }
	return (str);
}
