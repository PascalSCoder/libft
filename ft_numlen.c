/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 12:52:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/22 12:56:01 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_numlen(long number)
{
	size_t			count;

	count = 1;
	if (number < 0)
		count++;
	while (number / 10)
	{
		count++;
		number /= 10;
	}
	return (count);
}
