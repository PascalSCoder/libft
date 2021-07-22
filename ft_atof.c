/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 13:07:50 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/22 12:57:03 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_remainder(char *str)
{
	double	result;
	double	division;

	division = 10;
	result = 0;
	while (ft_isdigit(*str))
	{
		result += (*str - '0') / division;
		division *= 10;
		str++;
	}
	return (result);
}

double	ft_atof(char *str)
{
	double	result;
	char	sign;

	if (!str)
		return (0);
	result = 0;
	while (*str && ft_iswhitespace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
		sign = 1;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (*str == '.')
		result += get_remainder(str + 1);
	return (result * sign);
}
