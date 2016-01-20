/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:46:25 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/28 13:33:56 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	k;

	k = 0;
	j = s1 == NULL ? ft_strlen(s2) : ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = s1 == NULL ? 0 : -1;
	while (s1 && ++i < ft_strlen(s1))
		str[i] = s1[i];
	while (i < j && s2[k])
		str[i++] = s2[k++];
	str[i] = '\0';
	return (str);
}
