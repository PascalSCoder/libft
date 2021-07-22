/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_f.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 13:30:25 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:56:16 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

char		arg_double(va_list args, t_flags flags, int *written)
{
	double		number;
	t_argdata	data;
	char		result;
	char		*str_out;

	ft_bzero(&data, sizeof(data));
	number = (double)va_arg(args, typeof(double));
	data.str = ft_dtoa(number);
	if (!data.str)
		return (0);
	data.len = ft_strlen(data.str);
	if (number < 0)
		data.prefix = "-";
	str_out = compose_output(flags, &data);
	free(data.str);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}
