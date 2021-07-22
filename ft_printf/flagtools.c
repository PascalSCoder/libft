/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flagtools.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/03 16:14:08 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:55:42 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

void	fw_to_precision(t_flags *flags, t_argdata *data)
{
	if (flags->field_width > (int)data->len && flags->zero && !flags->minus)
	{
		flags->precision = flags->field_width;
		flags->field_width = 0;
		flags->has_precision = 1;
		if (data->prefix && ft_strlen(data->prefix))
			flags->precision -= 1;
	}
}
