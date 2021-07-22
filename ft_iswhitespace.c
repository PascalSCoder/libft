/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iswhitespace.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:22:02 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/01/06 17:26:16 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	ft_iswhitespace(const char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}
