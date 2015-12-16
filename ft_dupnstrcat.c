/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupnstrcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:49:20 by tiprata           #+#    #+#             */
/*   Updated: 2015/12/16 15:49:23 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_dupnstrcat(char *s1, char *s2, int n)
{
  char *str;
  str = ft_strnjoin(s1, s2, n);
  free (s1);
  return (str);
}
