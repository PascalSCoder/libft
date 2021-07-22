/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:47:33 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 13:00:15 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*get_next_word(char *start, char c, int *len)
{
	*len = 0;
	while (*start == c)
		start++;
	if (*start == '\0')
		return (0);
	while (*(start + *len) != c && *(start + *len) != '\0')
		*len += 1;
	return (start);
}

static char	**malloc_splits(char *string, char c, int *splits)
{
	int		length;
	char	*result;
	char	**buffer;

	*splits = 0;
	while (string && *string)
	{
		result = get_next_word(string, c, &length);
		if (result)
		{
			*splits += 1;
			string = result + length;
		}
		else
			break ;
	}
	buffer = (char **)malloc((*splits + 1) * sizeof(char *));
	return (buffer);
}

static void	free_splits(char **buffer, int i)
{
	while (i >= 0)
	{
		free(buffer[i]);
		i--;
	}
	free(buffer);
}

static char	*split_str(char *s, int length)
{
	char	*split;

	split = (char *)malloc((length + 1) * sizeof(char));
	if (!split)
		return (0);
	ft_strlcpy(split, s, length + 1);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		splits;
	int		splits_done;
	int		length;
	char	**buffer;

	splits_done = 0;
	buffer = malloc_splits((char *)s, c, &splits);
	if (buffer)
	{
		while (splits_done < splits)
		{
			s = get_next_word((char *)s, c, &length);
			buffer[splits_done] = split_str((char *)s, length);
			s += length;
			if (!buffer[splits_done])
			{
				free_splits(buffer, splits_done);
				return (0);
			}
			splits_done++;
		}
		buffer[splits] = 0;
	}
	return (buffer);
}
