/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_decitohex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:11:14 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/22 13:03:48 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_len(unsigned long long number)
{
	size_t	len;

	len = 1;
	while (number / 16)
	{
		number /= 16;
		len++;
	}
	return (len);
}

static void	subtract(unsigned long long number, size_t i, char *hex)
{
	char	remainder;

	if (number / 16)
		subtract(number / 16, i - 1, hex);
	remainder = number % 16;
	if (remainder < 10)
		hex[i] = 48 + remainder;
	else
		hex[i] = 55 + remainder;
}

char	*ft_decitohex(unsigned long long number)
{
	char	*hex;
	size_t	len;

	len = get_len(number);
	hex = malloc(len + 1);
	if (!hex)
		return (0);
	subtract(number, len - 1, hex);
	hex[len] = '\0';
	return (hex);
}
