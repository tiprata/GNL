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
	if (!(str = ft_strjoin(str, s1)))
		return (NULL);
	return (str);
}
