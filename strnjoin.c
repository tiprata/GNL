/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:13:57 by tiprata           #+#    #+#             */
/*   Updated: 2015/12/16 17:14:05 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
  int	i;
  int	j;
  char	*str;
  int	k;

  k = 0;
  j = ft_strlen(s1) + ft_strlen(s2) - n;
  if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
    return (NULL);
  i = -1;
  while (++i < ft_strlen(s1))
    str[i] = s1[i];
  while (i <= j && s2[k])
    {
      str[i++] = s2[k++];
    }
  str[i] = '\0';
  return (str);
}
