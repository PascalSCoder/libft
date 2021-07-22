/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:48:17 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 12:48:53 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[i] && haystack[j + i] == needle[i] && (i + j) < len)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		j++;
	}
	return (0);
}
