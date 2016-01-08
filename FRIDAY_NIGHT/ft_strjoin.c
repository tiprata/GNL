/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:46:25 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/04 13:31:53 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*str;
	int	k;

	k = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while (i < j && s2[k])
			str[i++] = s2[k++];
	str[i] = '\0';
	return (str);
}
