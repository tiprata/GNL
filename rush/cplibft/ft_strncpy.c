/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:53:46 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/16 13:40:08 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dst[j] = '\0';
		j++;
	}
	return (dst);
}
