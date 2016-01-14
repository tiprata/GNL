/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:45:37 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/14 16:52:26 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s1);
	if (!(str = (char*)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}
