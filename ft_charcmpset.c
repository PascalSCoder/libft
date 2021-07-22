/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_charcmpset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 13:29:46 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/22 13:02:15 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	ft_charcmpset(char ch, char *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}
