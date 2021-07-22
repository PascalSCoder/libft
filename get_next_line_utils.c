/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 12:19:18 by pascal        #+#    #+#                 */
/*   Updated: 2021/01/07 13:55:07 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

t_fd	*fd_create(int fd)
{
	t_fd	*tmp;

	tmp = (t_fd*)malloc(sizeof(t_fd));
	if (!tmp)
		return (0);
	tmp->fd = fd;
	tmp->next = 0;
	tmp->prev = 0;
	tmp->buffers = 0;
	tmp->last = 0;
	tmp->start = 0;
	tmp->end = 0;
	return (tmp);
}

t_fd	*fd_fetch(t_fd **lst, int fd)
{
	t_fd	*tmp;
	t_fd	*new;

	tmp = *lst;
	if (*lst)
	{
		while (1)
		{
			if (tmp->fd == fd)
			{
				tmp->start = tmp->end;
				return (tmp);
			}
			else if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
	}
	new = fd_create(fd);
	new->prev = tmp;
	if (tmp && new)
		tmp->next = new;
	else if (new)
		*lst = new;
	return (new);
}

t_list	*lstcreateadd(t_list **lst)
{
	t_list	*tmp;
	t_list	*item;

	item = (t_list*)malloc(sizeof(t_list));
	if (!item)
		return (0);
	item->next = 0;
	item->buffer = (char*)malloc(BUFFER_SIZE + 1);
	if (!item->buffer)
	{
		free(item);
		return (0);
	}
	if (!*lst)
		*lst = item;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = item;
	}
	return (item);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	count;

	if (lst)
		count = 1;
	else
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_lstclear(t_fd **fd_list, t_fd *fd_data, t_list *lst, int result)
{
	t_list	*tmp;

	if (!fd_list || !lst)
		return ;
	while (lst->next)
	{
		tmp = lst->next;
		free(lst->buffer);
		free(lst);
		lst = tmp;
	}
	fd_data->buffers = lst;
	if (result > 0)
		return ;
	if (!fd_data->prev)
		*fd_list = fd_data->next;
	else
		fd_data->prev->next = fd_data->next;
	if (fd_data->next)
		fd_data->next->prev = fd_data->prev;
	free(lst->buffer);
	free(lst);
	free(fd_data);
}
