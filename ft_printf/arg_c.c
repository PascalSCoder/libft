/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_c.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:39:40 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:56:22 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

static void	flagrestr(t_flags *flags)
{
	flags->has_precision = 0;
	flags->zero = 0;
}

char		arg_char(va_list args, t_flags flags, int *written)
{
	t_argdata	data;
	char		*str_out;
	char		result;

	ft_bzero(&data, sizeof(data));
	data.str = (char*)malloc(1);
	if (!data.str)
		return (0);
	data.str[0] = (char)va_arg(args, typeof(int));
	flagrestr(&flags);
	data.len = 1;
	str_out = compose_output(flags, &data);
	free(data.str);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}
