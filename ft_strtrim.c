/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:48:20 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 12:50:04 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_end(char const *s1, char const *set)
{
	int	i;
	int	end;

	end = ft_strlen((char *)s1);
	if (end < 0)
		return (0);
	while (end > 0)
	{
		i = 0;
		while (set[i])
		{
			if (s1[end - 1] == set[i])
			{
				i = -1;
				break ;
			}
			i++;
		}
		if (i == -1)
			end--;
		else
			break ;
	}
	return (end);
}

static int	get_start(char const *s1, char const *set)
{
	int	i;
	int	start;

	start = 0;
	while (s1[start])
	{
		i = 0;
		while (set[i])
		{
			if (s1[start] == set[i])
			{
				i = -1;
				break ;
			}
			i++;
		}
		if (i == -1)
			start++;
		else
			break ;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buffer;
	int		end_index;
	int		start_index;

	if (!s1 || !set)
		return (0);
	start_index = get_start(s1, set);
	end_index = get_end(s1, set);
	if (end_index < start_index)
	{
		start_index = 0;
		end_index = 0;
	}
	buffer = (char *)ft_calloc((end_index - start_index) + 1, sizeof(char));
	ft_strlcpy(buffer, s1 + start_index, (end_index - start_index) + 1);
	return (buffer);
}
