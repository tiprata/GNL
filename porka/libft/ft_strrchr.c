/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:49:04 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/24 17:39:17 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (s[i] != c && i)
		i--;
	if (s[i] == c)
		return ((char *)&s[i]);
	else	if (s[ft_strlen(s)] == c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
