/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flourme <flourme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:19:58 by flourme           #+#    #+#             */
/*   Updated: 2015/12/14 13:34:17 by flourme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int	i;

	i = 0;
	while (len != 0)
	{
		((unsigned char *)str)[i] = c;
		i++;
		len--;
	}
	return ((void *)str);
}
