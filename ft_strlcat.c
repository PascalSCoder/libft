/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:48:07 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 12:48:16 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + ft_strlen((char *)src));
	else if (size <= 0)
		return (0);
	i = dst_len;
	while (i < size - 1 && src[i - dst_len])
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src) + dst_len);
}
