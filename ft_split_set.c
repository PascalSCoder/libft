/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_set.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 13:05:16 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/22 12:38:02 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*get_till_set(char *str, char *set)
{
	while (*str)
	{
		if (ft_charcmpset(*str, set))
			break ;
		str++;
	}
	return (str);
}

static size_t	count_splits(char *str, char *set)
{
	size_t	split_count;

	split_count = 0;
	while (1)
	{
		while (*str && ft_charcmpset(*str, set))
			str++;
		if (!*str)
			break ;
		str = get_till_set(str, set);
		split_count++;
	}
	return (split_count);
}

static char	*cpy_split(char *start, char *end)
{
	char	*split;
	size_t	i;

	split = (char *)malloc((end - start) + 1);
	if (!split)
		return (0);
	i = 0;
	while (start != end)
	{
		split[i] = *start;
		start++;
		i++;
	}
	split[i] = '\0';
	return (split);
}

static char	**free_splits(char **splits)
{
	char	**tmp;

	if (splits)
	{
		tmp = splits;
		while (*tmp)
		{
			free(*tmp);
			tmp++;
		}
		free(splits);
	}
	return (0);
}

char	**ft_split_set(char *str, char *set)
{
	char	**splits;
	char	*end;
	char	*spl;
	size_t	count;

	if (!str || !set)
		return (0);
	count = count_splits(str, set);
	splits = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!splits)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str && ft_charcmpset(*str, set))
			str++;
		end = get_till_set(str, set);
		spl = cpy_split(str, end);
		if (!spl)
			return (free_splits(splits));
		str = end;
		splits[count] = spl;
		count++;
	}
	return (splits);
}
