/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 22:18:20 by pascal        #+#    #+#                 */
/*   Updated: 2021/01/06 20:24:57 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

size_t		ft_strncpy(char *dest, char *buffer, size_t i)
{
	size_t	j;

	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		dest[i + j] = buffer[j];
		j++;
	}
	return (j);
}

char		*combine_list(t_list *buffer_list, size_t end, size_t start)
{
	size_t		elements;
	size_t		elem_done;
	size_t		i;
	char		*line;

	elements = ft_lstsize(buffer_list);
	line = (char*)malloc(((elements - 1) * BUFFER_SIZE) + end - start + 1);
	if (!line)
		return (0);
	elem_done = 0;
	i = 0;
	while (buffer_list)
	{
		if (elem_done == 0)
			i += ft_strncpy(line, buffer_list->buffer + start, i);
		else
			i += ft_strncpy(line, buffer_list->buffer, i);
		buffer_list = buffer_list->next;
		elem_done++;
	}
	line[i] = '\0';
	return (line);
}

int			check_buffer(char *buffer, size_t *end)
{
	size_t	i;

	i = *end;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			*end = i + 1;
			return (line_done);
		}
		i++;
	}
	if (i < BUFFER_SIZE)
	{
		*end = i;
		return (file_done);
	}
	*end = 0;
	return (processing);
}

int			create_element(t_fd *fd_data)
{
	long long	bytes_read;
	t_list		*new;

	new = lstcreateadd(&fd_data->buffers);
	if (!new)
		return (error);
	fd_data->last = new;
	bytes_read = read(fd_data->fd, new->buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (error);
	new->buffer[bytes_read] = '\0';
	return (processing);
}

int			get_next_line(int fd, char **line)
{
	static t_fd		*fd_list;
	t_fd			*fd_data;
	int				result;

	fd_data = fd_fetch(&fd_list, fd);
	result = processing;
	if (!fd_data || !line || BUFFER_SIZE < 1 || fd < 0)
		result = error;
	while (result == processing)
	{
		if (fd_data->last)
			result = check_buffer(fd_data->last->buffer, &fd_data->end);
		if (result == processing)
			result = create_element(fd_data);
		else if (result == line_done || result == file_done)
			*line = combine_list(fd_data->buffers, fd_data->end,
			fd_data->start);
	}
	ft_lstclear(&fd_list, fd_data, fd_data->buffers, result);
	return (result);
}
