/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:48:06 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 12:48:16 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	strlen1;
	size_t	strlen2;

	if (!s1 || !s2)
		return (0);
	strlen1 = ft_strlen((char *)s1);
	strlen2 = ft_strlen((char *)s2);
	buffer = (char *)malloc(sizeof(char) * (strlen1 + strlen2 + 1));
	if (!buffer)
		return (0);
	ft_memcpy(buffer, s1, strlen1);
	ft_memcpy(buffer + strlen1, s2, strlen2);
	buffer[strlen1 + strlen2] = '\0';
	return (buffer);
}
