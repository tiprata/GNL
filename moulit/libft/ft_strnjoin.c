/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 19:06:53 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/07 19:09:43 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
  int	i;
  int	j;
  char	*str;
  int	k;

  k = 0;
  j = ft_strlen(s1) + ft_strlen(s2) - (ft_strlen(s2) - n);
  if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
    return (NULL);
  i = -1;
  while (++i < (int)ft_strlen(s1))
    str[i] = s1[i];
  while (i <= j && s2[k])
    {
      str[i++] = s2[k++];
    }
  str[i] = '\0';
  return (str);
}
