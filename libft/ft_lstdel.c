/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:37:18 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/12 20:18:09 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst && *alst && del)
	{
		temp = *alst;
		while (temp)
		{
			temp = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = temp;
		}
		*alst = NULL;
	}
}
