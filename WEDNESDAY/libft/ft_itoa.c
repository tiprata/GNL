/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:36:15 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/27 20:19:23 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_lenbr(n))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = (n < 0 ? -n : n);
	if (n < 0)
		str[j++] = '-';
	while (i)
	{
		if (n >= 0)
			str[ft_lenbr(i) - 1] = (i % 10) + 48;
		else
			str[ft_lenbr(i)] = (i % 10) + 48;
		i = i / 10;
		j++;
	}
	if (n == 0)
		str[j++] = '0';
	str[j] = '\0';
	return (str);
}
