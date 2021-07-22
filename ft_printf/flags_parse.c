/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_parse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:28:52 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:55:44 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static void	parse_digits(char **input, int *out)
{
	while (ft_isdigit(**input))
	{
		*out *= 10;
		*out += **input - '0';
		*input += 1;
	}
}

void		parse_fw(char **input, t_flags *flags, va_list args)
{
	int	value;

	if (**input == '*')
	{
		value = (int)va_arg(args, typeof(int));
		if (value < 0)
		{
			flags->minus = 1;
			value *= -1;
		}
		flags->field_width = value;
		*input += 1;
	}
	else if (ft_isdigit(**input))
		parse_digits(input, &flags->field_width);
}

void		parse_precision(char **input, t_flags *flags, va_list args)
{
	int	value;

	if (**input == '.')
	{
		flags->has_precision = 1;
		*input += 1;
	}
	if (**input == '*')
	{
		*input += 1;
		value = (int)va_arg(args, typeof(int));
		if (value < 0)
		{
			flags->has_precision = 0;
			return ;
		}
		flags->precision = value;
	}
	else if (ft_isdigit(**input))
		parse_digits(input, &flags->precision);
	else
		return ;
	flags->has_precision = 1;
}

void		parse_typemodifier(char **input, t_flags *flags)
{
	while (**input == 'l')
	{
		flags->l += 1;
		*input += 1;
	}
	if (flags->l)
		return ;
	while (**input == 'h')
	{
		flags->h += 1;
		*input += 1;
	}
}

void		parse_flags(char **input, t_flags *flags)
{
	while (1)
	{
		if (**input == '-')
			flags->minus = 1;
		else if (**input == '0')
			flags->zero = 1;
		else if (**input == ' ')
			flags->whitespace = 1;
		else if (**input == '+')
			flags->plus = 1;
		else if (**input == '#')
			flags->hashtag = 1;
		else
			break ;
		*input += 1;
	}
}
