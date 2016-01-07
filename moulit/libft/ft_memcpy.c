/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:39:25 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/24 18:06:29 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*tmp;
	size_t	i;

	i = -1;
	tmp = dst;
	while (++i < n)
		((char *)dst)[i] = ((const char *)src)[i];
	return (tmp);
}
