/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupstrcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 19:02:22 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/07 19:08:59 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_dupstrcat(char *s1, char *s2)
{
    char *str;

    if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1 +
			       ft_strlen(s2))))
      return (NULL);
    str = ft_strjoin(s1, s2);
    free (s1);
    return (str);
}
