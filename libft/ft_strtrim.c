/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:13:59 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/13 15:15:15 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end != 0)
		end--;
	if (start >= end)
		return (ft_strdup(""));
	res = ft_strsub(s, start, end - start + 1);
	return (res);
}
