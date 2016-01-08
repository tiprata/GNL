/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupstrcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:30:36 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/08 17:30:37 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
