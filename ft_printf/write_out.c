/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_out.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 11:52:35 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:55:22 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft.h"

char		write_out(char *str, size_t len, int *written)
{
	int		result;

	if (!str)
		return (0);
	result = write(1, str, len);
	if (result == -1)
		return (0);
	*written += result;
	return (1);
}

char		write_till_param(char **input, int *written)
{
	char	*pos;
	int		result;

	pos = ft_strchr(*input, '%');
	if (!pos)
	{
		result = write_out(*input, ft_strlen(*input), written);
		*input += ft_strlen(*input);
	}
	else
	{
		result = write_out(*input, pos - *input, written);
		*input += pos - *input;
	}
	return (result);
}
