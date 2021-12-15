/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:56:11 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/13 17:58:54 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
