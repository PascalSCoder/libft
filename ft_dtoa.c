/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dtoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 16:10:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/22 12:51:55 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	subtract(double n, char *buffer)
{
	if ((unsigned long long)n / 10)
		subtract(n / 10, buffer - 1);
	*buffer = ((unsigned long long)n % 10) + '0';
}

static char	*get_whole(double n, size_t *whole_count)
{
	char	*buffer;
	size_t	len;
	double	ndup;

	len = 1;
	ndup = n;
	while ((unsigned long long)ndup / 10)
	{
		len++;
		ndup /= 10;
	}
	buffer = malloc(len + 17);
	if (!buffer)
		return (0);
	subtract(n, buffer + len - 1);
	*whole_count = len;
	buffer[len] = '.';
	return (buffer);
}

static void	add_remainder(double n, char *buffer)
{
	size_t	i;
	char	digit;

	i = 0;
	while (i < 15)
	{
		digit = (char)((unsigned long long)(n * 10) % 10) + '0';
		if (digit < '0')
			digit = '0';
		buffer[i] = digit;
		n *= 10;
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_dtoa(double n)
{
	char	*str;
	size_t	whole_count;

	str = get_whole(n, &whole_count);
	if (!str)
		return (0);
	add_remainder(n, str + whole_count + 1);
	return (str);
}
