/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:32:14 by trnguyen          #+#    #+#             */
/*   Updated: 2021/11/18 15:56:52 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbrlen(long n)
{
	unsigned int	len;

	len = 1;
	if (n < 0)
	{
		len = len + 1;
		n = -n;
	}
	if (n > 9)
		len = len + ft_nbrlen(n / 10);
	return (len);
}

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	i;
	long			nb;

	nb = n;
	i = ft_nbrlen(nb);
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (num == NULL)
		return (NULL);
	num[i--] = '\0';
	if (nb == 0)
		num[0] = '0';
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		num[i--] = '0' + nb % 10;
		nb = nb / 10;
	}
	return (num);
}
