/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:15:50 by trnguyen          #+#    #+#             */
/*   Updated: 2021/12/12 20:34:57 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *begin_list)
{
	int		size;
	t_list	*lst;

	size = 0;
	lst = begin_list;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
