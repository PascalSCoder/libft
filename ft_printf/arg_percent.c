/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_percent.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:06:20 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:56:06 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

static void	flagrestr(t_flags *flags, t_argdata *data)
{
	if (flags->minus && flags->zero)
		flags->zero = 0;
	if (!flags->has_precision)
		fw_to_precision(flags, data);
}

char		arg_percent(t_flags flags, int *written)
{
	t_argdata	data;
	char		result;
	char		*str_out;

	ft_bzero(&data, sizeof(data));
	data.str = malloc(1);
	if (!data.str)
		return (0);
	data.str[0] = '%';
	data.len = 1;
	flagrestr(&flags, &data);
	str_out = compose_output(flags, &data);
	free(data.str);
	result = write_out(str_out, data.len, written);
	if (str_out)
		free(str_out);
	return (result);
}
