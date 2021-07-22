/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compose.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 17:08:31 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:55:51 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

static char	add_prec(t_bytelist **list, t_flags flags)
{
	t_bytelist	*new;
	char		*str;

	if (!flags.has_precision || flags.precision <= (int)(*list)->len)
		return (1);
	str = (char*)malloc(flags.precision - (*list)->len);
	if (!str)
		return (0);
	str = (char*)ft_memset(str, '0', flags.precision - (*list)->len);
	new = bytelist_new(str, flags.precision - (*list)->len);
	if (!new)
	{
		free(str);
		return (0);
	}
	bytelist_addfront(list, new);
	return (1);
}

static char	add_fw(t_bytelist **list, t_flags flags)
{
	t_bytelist	*new;
	char		*str;
	size_t		len;

	len = bytelist_getlen(*list);
	if (flags.field_width <= (int)len)
		return (1);
	str = (char*)malloc(flags.field_width - len);
	if (!str)
		return (0);
	str = (char*)ft_memset(str, ' ', flags.field_width - len);
	new = bytelist_new(str, flags.field_width - len);
	if (!new)
	{
		free(str);
		return (0);
	}
	if (flags.minus)
		bytelist_addback(list, new);
	else
		bytelist_addfront(list, new);
	return (1);
}

static char	add_prefix(t_bytelist **list, char *prefix)
{
	t_bytelist	*new;
	char		*str;

	if (prefix && *prefix)
	{
		str = ft_memdup(prefix, ft_strlen(prefix));
		if (!str)
			return (0);
		new = bytelist_new(str, ft_strlen(prefix));
		if (!new)
			return (0);
		bytelist_addfront(list, new);
	}
	return (1);
}

static char	add_strcpy(t_bytelist **list, t_argdata *data)
{
	char	*cpy;

	if (data->len)
	{
		cpy = ft_memdup(data->str, data->len);
		if (!cpy)
			return (0);
	}
	else
		cpy = 0;
	*list = bytelist_new(cpy, data->len);
	if (!*list)
	{
		free(cpy);
		return (0);
	}
	return (1);
}

char		*compose_output(t_flags flags, t_argdata *data)
{
	t_bytelist	*list;
	char		result;
	char		*ret_str;

	result = add_strcpy(&list, data);
	if (!result)
		return (0);
	result = add_prec(&list, flags);
	if (!result)
		return (bytelist_free(list));
	result = add_prefix(&list, data->prefix);
	if (!result)
		return (bytelist_free(list));
	result = add_fw(&list, flags);
	if (!result)
		return (bytelist_free(list));
	data->len = bytelist_combine(list, &ret_str);
	bytelist_free(list);
	return (ret_str);
}
