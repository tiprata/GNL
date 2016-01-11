/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:50:03 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/24 17:51:21 by tiprata          ###   ########.fr       */
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
	while (x < y)
	{
		str[i] = s[x];
		i++;
		x++;
	}
	str[i] = '\0';
	return (str);
}
