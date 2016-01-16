/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:44:57 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/16 13:56:49 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t size;

	size = 0;
	if (src[0] == '\0')
		ft_greenstr("[]");
	while (src[size])
	{
		dest[size] = src[size];
		size++;
	}
	dest[size] = '\0';
	return (dest);
}
