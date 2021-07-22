/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulltoa.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:47:51 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 22:37:25 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	fill_buffer(unsigned long long number, char *buffer)
{
	if (number / 10)
		fill_buffer(number / 10, buffer - 1);
	*buffer = (number % 10) + '0';
}

char	*ft_ulltoa(unsigned long long number)
{
	char	*buffer;
	size_t	len;

	len = ft_unumlen(number);
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (0);
	fill_buffer(number, buffer + len - 1);
	buffer[len] = '\0';
	return (buffer);
}
