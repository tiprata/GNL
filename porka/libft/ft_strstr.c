/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:49:28 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/24 17:55:56 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j] && s1[i] && s2[j])
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)&s1[i - ft_strlen(s2)]);
			i = i - j + 1;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
