/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_free.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 23:26:44 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:26:54 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_split_free(char **splits)
{
	char	**tmp;

	tmp = splits;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(splits);
}
