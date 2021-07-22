/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 15:00:55 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 13:00:30 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_number(unsigned int n, int fd)
{
	char	c;

	if (n / 10)
		write_number(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_n;

	if (n < 0)
	{
		write(fd, "-", 1);
		abs_n = n * -1;
	}
	else
		abs_n = n;
	write_number(abs_n, fd);
}
