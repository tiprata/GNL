/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:36:42 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/25 18:31:41 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_line_count(char const *s, char c)
{
	size_t i;
	size_t result;
	size_t k;

	k = 0;
	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				if (s[++i] == '\0' && k == 0)
					return (result);
			result++;
		}
		else
		{
			k = 1;
			if (s[++i + 1] == '\0' && result == 0)
				return (1);
		}
	}
	return (s[i - 1] == c && k == 1 && result != 1 ? result - 1 : result);
}
