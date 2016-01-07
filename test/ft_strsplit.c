/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:49:17 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/07 14:54:44 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <string.h>

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;
	char	**str;

	x = 0;
	y = 0;
	i = 0;
	j = ft_line_count(s, c);
	ft_putnbr(j);
	ft_putendl("<-------- number ------");
	if (!(str = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		x = y;
		while (s[x] == c && s[x++])
			y = x;
		while (s[y] != c && s[y])
			y++;
		str[i] = ft_strxdup(s, x, y);
		i++;
		while (s[y] == c && s[y])
			y++;
	}
	str[i] = NULL;
	return (str);
}
