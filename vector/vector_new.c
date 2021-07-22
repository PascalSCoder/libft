/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 15:26:06 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/22 13:46:16 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"

/*
	Initializes a new t_vector struct with element size of parameter bytesize.
	For vectors storing pointers, use vector_newptr instead.
	Returns NULL on error.
*/
t_vector	*vector_new(unsigned int bytesize)
{
	t_vector	*vector;

	if (bytesize == 0)
		return (0);
	vector = ft_calloc(1, sizeof(t_vector));
	if (!vector)
		return (0);
	vector->bytesize = bytesize;
	vector->size = 1;
	vector->memb = ft_calloc(vector->size, vector->bytesize);
	if (!vector->memb)
	{
		free(vector);
		return (0);
	}
	return (vector);
}
