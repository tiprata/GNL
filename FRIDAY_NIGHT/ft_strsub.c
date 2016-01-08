/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:49:39 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/04 13:42:25 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	j = start;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (start < len + j)
	{
		if (s[start] == '\n')
		{
			ft_putchar('[');
			ft_putnbr(start);
			ft_putstr((char *)s);
			ft_putchar(']');
		}
		//	else
			str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);

}
