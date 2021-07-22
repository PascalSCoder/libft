/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:47:38 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 12:59:07 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	long long	value;
	int			multiplier;

	value = 0;
	multiplier = 0;
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			value = (value * 10) + *nptr - '0';
		else if (value == 0 && multiplier == 0 && (*nptr == ' '
				|| *nptr == '-' || *nptr == '+' || *nptr == '\t' || *nptr == '\v'
				|| *nptr == '\f' || *nptr == '\r' || *nptr == '\n'))
		{
			if (*nptr == '-')
				multiplier = -1;
			else if (*nptr == '+')
				multiplier = 1;
		}
		else
			break ;
		nptr++;
	}
	if (multiplier == 0)
		multiplier = 1;
	return ((value * multiplier));
}
