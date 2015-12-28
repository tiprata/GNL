/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra_toolbox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flourme <flourme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 22:01:13 by flourme           #+#    #+#             */
/*   Updated: 2015/12/17 23:08:52 by flourme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "ok.h"

int	ft_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	ft_putchar(char c)
{
  write(1, &c, 1);
}

void	ft_putstr(char *str)
{
  write(1, str, ft_strlen(str));
}

void    ft_pinkstr(char *str)
{
  ft_putstr("\x1B[35m");
  write(1, str, ft_strlen(str));
  ft_putstr("\033[0m");
}

void    ft_pinkchar(char c)
{
  ft_putstr("\x1B[35m");
  write(1, &c, 1);
  ft_putstr("\033[0m");
}

void    ft_redstr(char *str)
{
  ft_putstr("\x1B[31m");
  write(1, str, ft_strlen(str));
  ft_putstr("\033[0m");
}

void    ft_bluestr(char *str)
{
  ft_putstr("\x1B[36m");
  write(1, str, ft_strlen(str));
  ft_putstr("\033[0m");
}

void    ft_greenstr(char *str)
{
  ft_putstr("\x1B[32m");
  write(1, str, ft_strlen(str));
  ft_putstr("\033[0m");
}

void    ft_putnbr(int n)
{
  if (n == -2147483648)
    ft_putstr("-2147483648");
  if (n < 0 && n > -2147483648)
    {
      ft_putchar('-');
      n = -n;
    }
  if (n < 10 && n > -2147483648)
    ft_putchar(n + 48);
  else if (n > 9)
    {
      ft_putnbr(n / 10);
      ft_putnbr(n % 10);
    }
}

void    ft_putab(char **str)
{
  int i;

  i = 0;
  while (str[i])
    {
      ft_putstr("\x1B[32m");
      ft_putstr(str[i]);
      ft_putchar('\n');
      ft_putstr("\033[0m");
      i++;
    }
}

void    *ft_memset(void *str, int c, size_t len)
{
  int     i;

  i = 0;
  while (len != 0)
    {
      ((unsigned char *)str)[i] = c;
      i++;
      len--;
    }
  return ((void *)str);
}

void    *ft_memalloc(size_t size)
{
  void    *result;

  if (size == 0)
    return (NULL);
  result = (void *)malloc(size);
  if (result)
    ft_memset(result, 0, size);
  return (result);
}

int     ft_tablen(char **str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     ft_check_hor_len_high(char **str)
{
  int i;
  int j;
  int stop;
  int ok;

  ok = 0;
  stop = 0;
  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i][j])
        {
          if (str[i][j] == '#')
	    stop = 1;
          j++;
        }
      if (stop == 1)
        break ;
      ok = stop == 1 ? ok : ok + 1;
      j = 0;
      i++;
    }
  return (ok);
}

char    **ft_resize1(char **str)
{
  int i;
  int j;
  char **tab;
  int ok;

  ok = 0;
  i = 0;
  j = 0;
  ok = ft_check_hor_len_high(str);
  if (!(tab = (char **)ft_memalloc(sizeof(char *) * ft_tablen(str) - ok + 1)))
    return (NULL);
  while (str[ok])
    {
      if (!(tab[i] = (char *)ft_memalloc(sizeof(char) * ft_strlen(str[0]))))
        return (NULL);
      while (str[ok][j])
        {
          tab[i][j] = str[ok][j];
          j++;
        }
      j = 0;
      i++;
      ok++;
    }
  return (tab);
}


int     ft_check_vert_len_right(char **str)
{
  int i;
  int j;
  int stop;
  int ok;

  i = 0;
  j = ft_strlen(str[0]) - 1;
  stop = 0;
  ok = 0;
  while (stop != 1)
    {
      while (str[i])
        {
          if (str[i][j] == '#')
            stop = 1;
          i++;
        }
      if (stop == 1)
        break;
      ok = stop == 1 ? ok : ok + 1;
      j--;
      i = 0;
    }
  return (ok);
}

char    **ft_resize2(char **str)
{
  int i;
  int j;
  char **tab;
  int ok;

  ok = 0;
  i = 0;
  j = 0;

  ok = ft_check_vert_len_right(str);
  if (!(tab = (char **)ft_memalloc(sizeof(char *) * ft_tablen(str) + 1)))
    return (NULL);
  while (str[i])
    {
      if (!(tab[i] = (char *)ft_memalloc(sizeof(char) * ft_strlen(str[0]) - ok\
					 )))
        return (NULL);
      while (j < ft_strlen(str[0]) - ok)
        {
          tab[i][j] = str[i][j];
          j++;
        }
      j = 0;
      i++;
    }
  return (tab);
}

int     ft_check_hor_length_down(char **str)
{
  int i;
  int j;
  int stop;
  int ok;

  ok = 0;
  stop = 0;
  i = ft_tablen(str) - 1;
  j = 0;
  ft_putnbr(i);
  while (i >= 0)
    {
      while (str[i][j])
	if (str[i][j++] == '#')
	  stop = 1;
      if (stop == 1)
        break ;
      ok = stop == 1 ? ok : ok + 1;
      j = 0;
      i--;
    }
  return (ok);
}

char    **ft_resize3(char **str)
{
  int i;
  int j;
  char **tab;
  int ok;
  int start;

  start = 0;
  ok = 0;
  i = 0;
  j = 0;
  ok = ft_check_hor_length_down(str);
  if (!(tab = (char **)ft_memalloc(sizeof(char *) * ft_tablen(str) - ok + 1)))
    return (NULL);
  while (str[start] && start < ft_tablen(str) - ok)
    {
      if (!(tab[i] = (char *)ft_memalloc(sizeof(char) * ft_strlen(str[0]))))
        return (NULL);
      while (str[start][j])
        {
          tab[i][j] = str[start][j];
          j++;
        }
      j = 0;
      start++;
      i++;
    }
  return (tab);

}
/*
char    **ft_resize4(char **str)
{

}*/

int     main(void)
{
  int i = 0;
  char **str;
  str = (char **)malloc(sizeof(char *) + 5);
  str[0] = (char *)malloc(sizeof(char) + 5);
  str[1] = (char *)malloc(sizeof(char) + 5);
  str[2] = (char *)malloc(sizeof(char) + 5);
  str[3] = (char *)malloc(sizeof(char) + 5);
  str[0] = "....";
  str[1] = ".##.";
  str[2] = ".##.";
  str[3] = "....";
  str[4] = NULL;

  str = ft_resize1(str);
  str = ft_resize2(str);
  ft_putab(str);
  str = ft_resize3(str);
  // str = ft_essential(str);
  ft_greenstr("DA RESULT\n");
  while (str[i])
    {
      ft_putstr(str[i]);
      ft_putchar('\n');
      i++;
    }
  return (0);
}
