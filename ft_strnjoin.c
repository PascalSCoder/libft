/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnjoin.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:52:45 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/22 13:04:08 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

static char	*combine(char **strs, size_t totallen)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(totallen + 1);
	if (!str)
		return (0);
	i = 0;
	while (*strs)
	{
		j = 0;
		while ((*strs)[j])
		{
			str[i] = (*strs)[j];
			j++;
			i++;
		}
		strs++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	get_args(va_list args, char **strs, size_t n)
{
	size_t	i;
	size_t	strslen;

	i = 0;
	strslen = 0;
	while (i < n)
	{
		strs[i] = (char *)va_arg(args, typeof(char *));
		strslen += ft_strlen(strs[i]);
		i++;
	}
	strs[i] = 0;
	return (strslen);
}

char	*ft_strnjoin(size_t n, ...)
{
	va_list	args;
	char	**strs;
	char	*str;
	size_t	strslen;

	if (n <= 0)
		return (0);
	va_start(args, n);
	strs = (char **)malloc(sizeof(char *) * (n + 1));
	if (!strs)
		return (0);
	strslen = get_args(args, strs, n);
	str = combine(strs, strslen);
	free(strs);
	va_end(args);
	return (str);
}
