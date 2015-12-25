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


char	**ft_resize_map(char **str, t_pos lpos, t_pos rtpos)
{
  char **ret;
  int tmp;
  int i;
  int j;
  int tmp2;

  tmp2 = lpos.x;
  j = 0;
  i = 0;
  tmp = 0;
  if (!(ret = (char **)malloc(sizeof(char *) * rtpos.x + 1)))
    return (NULL);
  while (i <= rtpos.x)
    {
      tmp = lpos.y;
      if (!(ret[i] = (char *)malloc(sizeof(char) * rtpos.y - lpos.y + 1)))
	return (NULL);
      while (tmp <= rtpos.y && str[tmp2][tmp] && tmp2 <= rtpos.x)
	{
	  ret[i][j] = str[tmp2][tmp];
	  j++;
	  tmp++;
	}
      ret[i][j] = '\0';
      j = 0;
      i++;
      tmp2++;
    }
  ret[i] = NULL;
  return (ret);
}

t_pos	ft_rtpos(t_pos rtpos, char **tetra)
{
  int i;
  int tmp;
  int count;

  count = 0;
  i = 0;
  tmp = rtpos.y;
  while (tetra[rtpos.x + 1][tmp] == '#' && tetra[rtpos.x][tmp])
    {
      while (tetra[rtpos.x][tmp + count] == '#' && tetra[rtpos.x][tmp + count + 1])
	  count++;
      rtpos.y = count + tmp;
      rtpos.x++;
    }
  return (rtpos);
}

t_pos	ft_lpos(t_pos lpos, char **tetra)
{
  int i;
  int tmp;
  int count;
  int tmp2;

  count = 0;
  i = 0;
  tmp2 = lpos.x;
  tmp = lpos.y;
  while (tetra[tmp2 + 1][tmp] == '#' && tetra[tmp2][tmp])
    {
      while (tetra[tmp2][tmp - count] == '#' && tmp - count >= 0 && tetra[tmp2][tmp - count])
	count--; 
      lpos.y = count + tmp;
      tmp2++;
    }
  return (lpos);
}

char	**ft_essential(char **tetra)
{
  t_pos lpos;
  t_pos rtpos;
  char **str = NULL;

  rtpos.x = 0;
  rtpos.y = 0;
  lpos.x = 0;
  lpos.y = 0;
  while (tetra[lpos.x])
    {
      while (tetra[lpos.x][lpos.y])
	{
	  if (tetra[lpos.x][lpos.y] == '#' && lpos.x <= 3 && lpos.y <= 3)
	    {
	      rtpos = lpos;
	      rtpos = ft_rtpos(rtpos, tetra);
	      lpos = ft_lpos(lpos, tetra);
	      ft_putab(tetra);
	      str = ft_resize_map(tetra, lpos, rtpos);
	      return (str);
	    }
	  else
	    lpos.y++;
	}
      lpos.y = 0;
      lpos.x++;
    }
  return (NULL);
}

int	main(void)
{
  int i = 0;
  char **str;
  str = (char **)malloc(sizeof(char *) + 5);
  str[0] = (char *)malloc(sizeof(char) + 5);
  str[1] = (char *)malloc(sizeof(char) + 5);
  str[2] = (char *)malloc(sizeof(char) + 5);
  str[3] = (char *)malloc(sizeof(char) + 5);
  str[0] = "....";
  str[1] = "..#.";
  str[2] = ".###";
  str[3] = "....";
  str[4] = NULL;

  str = ft_essential(str);
  ft_greenstr("DA RESULT\n");
  while (str[i])
    {
      ft_putstr(str[i]);
            ft_putchar('\n');
      i++;
    }
  return (0);
}
