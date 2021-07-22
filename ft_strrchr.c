/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:48:18 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/22 12:52:10 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (*s)
	{
		if ((char)*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if (ptr == 0 && (char)*s == (char)c)
		return ((char *)s);
	return (ptr);
}
