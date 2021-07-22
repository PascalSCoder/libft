/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_x.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/03 17:47:21 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:56:00 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "../libft.h"

static void	flagrestr(t_flags *flags, t_argdata *data, char islower)
{
	if (flags->hashtag)
	{
		if (islower)
			data->prefix = "0x";
		else
			data->prefix = "0X";
	}
	else
		data->prefix = "";
	numflagrestr(flags, data);
}

char		arg_upperhex(va_list args, t_flags flags, int *written)
{
	unsigned long long	number;
	char				result;
	char				*str_out;
	t_argdata			data;

	ft_bzero(&data, sizeof(data));
	number = get_unsigned_arg(args, flags);
	data.str = ft_decitohex(number);
	if (!data.str)
		return (0);
	data.len = ft_strlen(data.str);
	flagrestr(&flags, &data, 0);
	str_out = compose_output(flags, &data);
	free(data.str);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}

char		arg_lowerhex(va_list args, t_flags flags, int *written)
{
	unsigned long long	number;
	char				result;
	char				*str_out;
	t_argdata			data;

	ft_bzero(&data, sizeof(data));
	number = get_unsigned_arg(args, flags);
	data.str = ft_decitohex(number);
	if (!data.str)
		return (0);
	data.len = ft_strlen(data.str);
	data.str = ft_strtolower(data.str);
	flagrestr(&flags, &data, 1);
	str_out = compose_output(flags, &data);
	free(data.str);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}
