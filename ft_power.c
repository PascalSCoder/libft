/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:11:48 by pspijkst      #+#    #+#                 */
/*   Updated: 2020/12/04 11:18:30 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long	ft_power(int n, int power)
{
	long long	value;

	value = 1;
	while (power > 0)
	{
		value = value * n;
		power--;
	}
	return (value);
}
