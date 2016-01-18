/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:45:37 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/17 17:08:23 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*str;

	str = NULL;
//	ft_redstr(s1);
//	ft_putnbr(ft_strlen(s1));
	if (!(str = ft_memalloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
//	str = ft_memalloc(1);
//	str[0] = '\0';
	if (!(str = ft_strjoin(str, s1)))
		return (NULL);

//	str = ft_strcpy(str, s1);
//	ft_redstr(s1);
//	str = ft_strsub(s1, 0, ft_strlen(s1));
//	ft_redstr(str);
	return (str);
}
