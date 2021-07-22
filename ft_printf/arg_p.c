/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_p.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:16:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:56:11 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

static void	flagrestr(t_flags *flags, char *str)
{
	if (flags->has_precision)
		if (flags->precision < (int)ft_strlen(str))
			flags->has_precision = 0;
	if (flags->field_width && flags->zero && !flags->has_precision
		&& flags->field_width > (int)ft_strlen(str))
	{
		flags->precision = flags->field_width;
		flags->has_precision = 1;
		flags->precision -= 2;
	}
}

char		arg_pointer(va_list args, t_flags flags, int *written)
{
	long long	ptr;
	char		result;
	char		*str_out;
	t_argdata	data;

	ft_bzero(&data, sizeof(data));
	ptr = (long long)va_arg(args, typeof(long long));
	data.str = ft_decitohex(ptr);
	if (!data.str)
		return (0);
	data.str = ft_strtolower(data.str);
	data.len = ft_strlen(data.str);
	flagrestr(&flags, data.str);
	data.prefix = "0x";
	str_out = compose_output(flags, &data);
	free(data.str);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}
