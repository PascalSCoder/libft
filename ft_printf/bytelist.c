/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bytelist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 11:27:28 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:55:54 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

t_bytelist	*bytelist_new(char *str, size_t len)
{
	t_bytelist	*new;

	new = malloc(sizeof(t_bytelist));
	if (!new)
		return (0);
	ft_bzero(new, sizeof(t_bytelist));
	new->buffer = str;
	new->len = len;
	return (new);
}

void		bytelist_addfront(t_bytelist **list, t_bytelist *new)
{
	if (*list)
		new->next = *list;
	*list = new;
}

void		bytelist_addback(t_bytelist **list, t_bytelist *new)
{
	t_bytelist	*tmp;

	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

size_t		bytelist_getlen(t_bytelist *list)
{
	size_t	len;

	len = 0;
	while (list)
	{
		len += list->len;
		list = list->next;
	}
	return (len);
}

size_t		bytelist_combine(t_bytelist *list, char **dest)
{
	size_t		len;
	size_t		i;

	len = bytelist_getlen(list);
	*dest = (char*)malloc(len);
	if (!*dest)
		return (0);
	i = 0;
	while (list)
	{
		ft_memcpy(*dest + i, list->buffer, list->len);
		i += list->len;
		list = list->next;
	}
	return (len);
}
