/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_di.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 15:30:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 14:01:36 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

long long			get_signed_arg(va_list args, t_flags flags)
{
	long long	number;

	if (flags.l == 2)
		number = (long long)va_arg(args, typeof(long long));
	else if (flags.l == 1)
		number = (long)va_arg(args, typeof(long));
	else if (flags.h == 2)
		number = (char)va_arg(args, typeof(int));
	else if (flags.h == 1)
		number = (short)va_arg(args, typeof(int));
	else
		number = (int)va_arg(args, typeof(int));
	return (number);
}

unsigned long long	get_unsigned_arg(va_list args, t_flags flags)
{
	unsigned long long	number;

	if (flags.l == 2)
		number = (unsigned long long)va_arg(args, typeof(unsigned long long));
	else if (flags.l == 1)
		number = (unsigned long)va_arg(args, typeof(unsigned long));
	else if (flags.h == 2)
		number = (unsigned char)va_arg(args, typeof(unsigned int));
	else if (flags.h == 1)
		number = (unsigned short)va_arg(args, typeof(unsigned int));
	else
		number = (unsigned int)va_arg(args, typeof(unsigned int));
	return (number);
}

void				numflagrestr(t_flags *flags, t_argdata *data)
{
	if (flags->minus && flags->zero)
		flags->zero = 0;
	if (!data->prefix && flags->plus)
		data->prefix = "+";
	else if (!data->prefix && flags->whitespace)
		data->prefix = " ";
	if (flags->has_precision)
	{
		if (*data->str == '0' && !flags->precision)
			data->len = 0;
	}
	else
		fw_to_precision(flags, data);
}

char				arg_signednum(va_list args, t_flags flags, int *written)
{
	long long			number;
	unsigned long long	abs_num;
	t_argdata			data;
	char				result;
	char				*str_out;

	ft_bzero(&data, sizeof(data));
	number = get_signed_arg(args, flags);
	if (number < 0)
		abs_num = number * -1;
	else
		abs_num = number;
	data.str = ft_ulltoa(abs_num);
	if (!data.str)
		return (0);
	data.len = ft_strlen(data.str);
	if (number < 0)
		data.prefix = "-";
	numflagrestr(&flags, &data);
	str_out = compose_output(flags, &data);
	free(data.str);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}

char				arg_unsignednum(va_list args, t_flags flags, int *written)
{
	unsigned long long	abs_num;
	t_argdata			data;
	char				result;
	char				*str_out;

	ft_bzero(&data, sizeof(data));
	abs_num = get_unsigned_arg(args, flags);
	data.str = ft_ulltoa(abs_num);
	if (!data.str)
		return (0);
	data.len = ft_strlen(data.str);
	numflagrestr(&flags, &data);
	str_out = compose_output(flags, &data);
	free(data.str);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}
