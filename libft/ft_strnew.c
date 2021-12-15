/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:57:32 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/12 23:13:18 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	ft_memset(new, 0, size + 1);
	return (new);
}
