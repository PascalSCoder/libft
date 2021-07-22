/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_s.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 09:29:20 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:56:04 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

static void	flagrestr(t_flags *flags, t_argdata *data)
{
	flags->zero = 0;
	if (!data->str)
		data->str = "(null)";
	data->len = ft_strlen(data->str);
	if (flags->has_precision)
	{
		if (flags->precision < (int)data->len)
			data->len = flags->precision;
		else
			flags->has_precision = 0;
	}
}

char		arg_string(va_list args, t_flags flags, int *written)
{
	t_argdata	data;
	char		*str_out;
	char		result;

	ft_bzero(&data, sizeof(data));
	data.str = (char*)va_arg(args, typeof(char*));
	flagrestr(&flags, &data);
	str_out = compose_output(flags, &data);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}
