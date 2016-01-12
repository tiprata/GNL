/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:42:42 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/24 17:34:17 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t size;
	size_t count;

	count = 0;
	size = ft_strlen(s1);
	while (s2[count])
	{
		s1[size] = s2[count];
		size++;
		count++;
	}
	s1[size] = '\0';
	return (s1);
}
