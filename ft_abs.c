/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 09:32:46 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/05/27 15:06:34 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long	ft_abs(long num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}