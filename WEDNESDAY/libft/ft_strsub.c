/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:49:39 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/14 16:51:15 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	j = start;
	i = 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (start < len + j)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
