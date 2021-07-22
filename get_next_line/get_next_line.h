/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 22:18:31 by pascal        #+#    #+#                 */
/*   Updated: 2021/07/22 13:43:46 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

enum	e_result
{
	error = -1,
	file_done = 0,
	line_done = 1,
	processing = 2
};

typedef struct	s_fd
{
	int				fd;
	size_t			end;
	size_t			start;
	struct s_fd		*next;
	struct s_fd		*prev;
	struct s_list	*buffers;
	struct s_list	*last;
}				t_fd;

typedef struct	s_list
{
	char			*buffer;
	struct s_list	*next;
}				t_list;

size_t			ft_strncpy(char *dest, char *buffer, size_t i);
int				get_next_line(int fd, char **line);
t_list			*lstcreateadd(t_list **lst);
size_t			ft_lstsize(t_list *lst);
void			ft_lstclear(t_fd **fd_list, t_fd *fd_data,
				t_list *lst, int result);
t_fd			*fd_fetch(t_fd **lst, int fd);

#endif
