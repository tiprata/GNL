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

int     ft_check_vert_len_left(char **str)
{
  int i;
  int j;
  int stop;
  int ok;

  i = 0;
  j = 0;
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
      j++;
      i = 0;
    }
  return (ok);
}

char    **ft_resize4(char **str)
{
  int i;
  int j;
  char **tab;
  int ok;
  int x;

  i = 0;
  x = 0;
  ok = ft_check_vert_len_left(str);
  j = ok;
  if (!(tab = (char **)ft_memalloc(sizeof(char *) * ft_tablen(str) + 1)))
    return (NULL);
  while (str[i])
    {
      if (!(tab[i] = (char *)ft_memalloc(sizeof(char) * ft_strlen(str[0]) - ok)))
        return (NULL);
      while (j < ft_strlen(str[0]))
          tab[i][x++] = str[i][j++];
      x = 0;
      j = ok;
      i++;
    }
  return (tab);
}

t_off ft_find_first_sharp(char **str, t_off pos)
{
  pos.x = 0;
  pos.y = 0;
  while (str[pos.x])
  {
    while (str[pos.x][pos.y])
    {
      if (str[pos.x][pos.y] == '#')
        return (pos)
      pos.y++;
    }
    pos.x++;
  }
  return (pos);
}

int   ft_is_stick(char **str)
{
  t_off pos;

  pos = ft_find_first_sharp(str, pos);
  if (str[pos.x][pos.y] == '\0')
    return (-1);
  if (pos.y == 0 && str[pos.x][pos.y + 1] == '#' && str[pos.x][pos.y + 2] == '#' && str[pos.x][pos.y + 3] == '#')
    return (1);
  if (pos.x == 0 && str[pos.x + 1][pos.y] == '#' && str[pos.x + 2][pos.y] == '#' && str[pos.x + 3][pos.y + 3] == '#')
    return (1);
  return (0);
}

int	ft_is_square(char **str)
{
  t_off pos;

  pos = ft_find_first_sharp(str, pos);
  if (str[pos.x][pos.y] == '\0')
    return (-1);
  if (pos.x < 3 && pos.y < 3 && str[pos.x][pos.y + 1] == '#' && str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y + 1] == '#')
    return (1);
  return (0);
} 

int	ft_is_l(char **str)
{
  t_off pos;

  pos = ft_find_first_sharp(str, pos);
  if (str[pos.x][pos.y] == '\0')
    return (-1);
  if (pos.x < 2 && pos.y < 3 && str[pos.x + 1][pos.y] == '#' && str[pos.x + 2][pos.y] == '#' && str[pos.x + 2][pos.y + 1] == '#')
    return (1);
  if (pos.x < 3 && pos.y > 1 && str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y - 1] == '#' && str[pos.x + 1][pos.y - 2] == '#')
    return (1);
  if (pos.x < 2 && pos.y < 3 && str[pos.x][pos.y + 1] == '#' && str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 2][pos.y + 1] == '#')
    return (1);
  if (pos.x < 3 && pos.y < 2 && str[pos.x][pos.y + 1] == '#' && str[pos.x][pos.y + 2] == '#' && str[pos.x + 1][pos.y] == '#')
    return (1);
  //IL MANQUE LA MOITIE
  return (0);
} 


int	ft_is_t(char **str)
{
  t_off pos;

  pos = ft_find_first_sharp(str, pos);
  if (str[pos.x][pos.y] == '\0')
    return (-1);
  if (pos.x < 3 && pos.y > 0 && pos.y < 3 && str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 1][pos.y - 1] == '#')
    return (1);
  if (pos.x < 2 && pos.y > 0 str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y - 1] == '#' && str[pos.x + 2][pos.y] == '#')
    return (1);
  if (pos.x > 0 && pos.y < 2 str[pos.x][pos.y + 1] == '#' && str[pos.x][pos.y + 2] == '#' && str[pos.x - 1][pos.y + 1] == '#')
    return (1);
  if (pos.x < 2 && pos.y < 3 && str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 2][pos.y] == '#')
    return (1);
  return (0);
} 

int   ft_is_sharp(char **str)
{
  t_off pos;

  pos = ft_find_first_sharp(str, pos);
  if (str[pos.x][pos.y] == '\0')
    return (-1);
  if (pos.y > 0 && pos.y < 3 && pos.x < 3 str[pos.x][pos.y + 1] == '#' && str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y - 1] == '#')
    return (1);
  if (pos.y < 2 && pos.x < 3 && str[pos.x][pos.y + 1] == '#' && str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 1][pos.y + 2] == '#')
    return (1);
  if (pos.x < 2 && pos.y < 3 && str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y + 1] == '#' && str[pos.x + 2][pos.y + 1] == '#')
    return (1);
  if (pos.y > 0 && pos.x < 2 && str[pos.x + 1][pos.y] == '#' && str[pos.x + 1][pos.y - 1] == '#' && str[pos.x + 2][pos.y - 1] == '#')
    return (1);
  return (0);
}

int   ft_check_error(t_tetra **list, char **str)
{
  int erret;

  erret = 0;
  if ((erret = ft_is_t(str)) && erret == 1)
    return (1);
  else if (erret == -1)
    return (-1);
  if ((erret = ft_is_square(str)) && errret = 1)
    return (1);
  else if (erret == -1)
    return (-1);
  if ((erret = ft_is_stick(str)) && erret = 1)
    return (1);
  else if (erret == -1)
    return (-1);
  if ((erret = ft_is_l(str)) && erret = 1)
    return (1);
  else if (erret == -1)
    return (-1);
  if ((erret = ft_is_sharp(str)) && erret = 1)
    return (1);
  else if (erret == -1)
    return (-1);
  if (erret == 0)
  return (-1);
}

int   ft_file_parser(int fd)
{
  t_tetra *list;
  char *line;
  char **tab;
  int i;

  i = 0;
  if (!(tab = (char **)ft_memalloc(sizeof(char *) * 5)))
   return (-1);
  while (get_next_line(fd, &line))
  {
    if (ft_strlen(line) == 4)
    {
      tab[i] = line;
    }
    else if (ft_strlen(line) == 0 && i == 4)
    {
      i = 0;
      ft_tetra_add(&list, tab);
      if (!(ft_check_error(&list, tab)))
        return (-1);
    }
  }
}

int     main(void)
{
  int i = 0;


  str = ft_resize1(str);
  str = ft_resize2(str);
  str = ft_resize3(str);
  str = ft_resize4(str);
  ft_greenstr("DA RESULT\n");
  while (str[i])
    {
      ft_putstr(str[i]);
      ft_putchar('\n');
      i++;
    }
  return (0);
}
