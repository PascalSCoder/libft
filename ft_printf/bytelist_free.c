/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bytelist2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 09:08:52 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/01/04 09:09:10 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char			*bytelist_free(t_bytelist *list)
{
	t_bytelist	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->buffer)
			free(tmp->buffer);
		free(tmp);
	}
	return (0);
}
