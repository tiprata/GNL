/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:50:03 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/07 14:54:00 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strxdup(char const *s, size_t x, size_t y)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * y - x + 1)))
		return (NULL);
	if (s[0] == '\n')
	{
		str[0] = '\0';
		return (str);
	}
	while (x < y)
	{
		str[i] = s[x];
		i++;
		x++;
	}
	str[i] = '\0';
	return (str);
}
