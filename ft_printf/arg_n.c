/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_n.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 13:46:18 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/01/03 17:28:24 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

char	arg_nwritten(va_list args, int *written)
{
	int		*arg;

	arg = (int*)va_arg(args, typeof(int*));
	if (arg)
		*arg = *written;
	else
		return (0);
	return (1);
}
