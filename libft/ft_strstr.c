/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strstr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: trnguyen <trnguyen@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/11/03 17:52:45 by trnguyen		  #+#	#+#			 */
/*   Updated: 2021/11/04 15:45:11 by trnguyen		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
