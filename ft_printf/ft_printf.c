/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 13:19:36 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:55:38 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

char		parse_type(const char *input, va_list args, t_flags flags,
			int *written)
{
	if (*input == 'c')
		return (arg_char(args, flags, written));
	else if (*input == 's')
		return (arg_string(args, flags, written));
	else if (*input == 'p')
		return (arg_pointer(args, flags, written));
	else if (*input == 'd' || *input == 'i')
		return (arg_signednum(args, flags, written));
	else if (*input == 'u')
		return (arg_unsignednum(args, flags, written));
	else if (*input == 'x')
		return (arg_lowerhex(args, flags, written));
	else if (*input == 'X')
		return (arg_upperhex(args, flags, written));
	else if (*input == '%')
		return (arg_percent(flags, written));
	else if (*input == 'n')
		return (arg_nwritten(args, written));
	else if (*input == 'f')
		return (arg_double(args, flags, written));
	else
		return (-1);
}

t_flags		parse_input(char **input, va_list args)
{
	t_flags flags;

	*input += 1;
	ft_bzero(&flags, sizeof(flags));
	parse_flags(input, &flags);
	parse_fw(input, &flags, args);
	parse_precision(input, &flags, args);
	parse_typemodifier(input, &flags);
	return (flags);
}

char		process_arg(char **str, va_list args, int *written)
{
	t_flags	flags;
	int		result;

	if (**str == '%')
	{
		flags = parse_input(str, args);
		result = parse_type(*str, args, flags, written);
		*str += 1;
		return (result);
	}
	return (1);
}

int			ft_printf(const char *input, ...)
{
	va_list	args;
	int		written;
	int		result;

	if (!input)
		return (0);
	written = 0;
	va_start(args, input);
	while (*input)
	{
		result = write_till_param((char**)&input, &written);
		if (!result)
		{
			written = -1;
			break ;
		}
		result = process_arg((char**)&input, args, &written);
		if (!result)
		{
			written = -1;
			break ;
		}
	}
	va_end(args);
	return (written);
}
