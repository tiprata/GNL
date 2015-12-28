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
  if (!(ret = ft_memalloc(rtpos.x + 1)))
    return NULL;
  while (i <= rtpos.x)
    {
      tmp = lpos.y;
      ft_putstr("rtpos.y - lpos.y + 1 = ");
      ft_putnbr(rtpos.y - lpos.y + 1);
      ft_putchar('\n');
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
  return (ret);
}

t_pos	ft_rtpos2(t_pos rtpos, char **tetra)
{
  int i;
  int tmp;
  int count;

  count = 0;
  i = 0;
  tmp = rtpos.x;
  ft_greenstr("JE SUIS DANS RTPOS2\n");
  while (rtpos.y < 4 && tetra[tmp][rtpos.y] && tetra[tmp][rtpos.y] == '#')
    {
      ft_redstr("JE SUIS DANS LE WHILE\n");
      ft_greenstr("tmp + count = ");
      ft_putnbr(tmp + count);
      ft_putchar('\n');
      ft_bluestr("rtpos.y = ");
      ft_putnbr(rtpos.y);
      ft_putchar('\n');
      //if (tetra[tmp + count][rtpos.y] == '#' && tmp + count < 4 && rtpos.y < 4)
      while (tetra[tmp + count][rtpos.y] == '#' && tmp + count < 4 && rtpos.y < 4)
	{
	  if (tetra[tmp + count + 1][rtpos.y] == '#')
	    {
	      ft_bluestr("COUNTPLUSPLUS\n");
	      count++;
	    }
	  else
	    break ;
	}
      if (rtpos.x < count + tmp)
	rtpos.x = count + tmp;
      rtpos.y++;
      count = 0;
    }
  return (rtpos);
}

t_pos	ft_rtpos(t_pos rtpos, char **tetra)
{
  int i;
  int tmp;
  int count;

  count = 0;
  i = 0;
  tmp = rtpos.y;
  if (rtpos.x < 4  && tetra[rtpos.x][tmp] && tetra[rtpos.x + 1][tmp] == '#')
    {
      while (rtpos.x < 4 && tetra[rtpos.x][tmp] && tetra[rtpos.x + 1][tmp] == '#')
	{
	  while (tetra[rtpos.x][tmp + count] == '#' && tmp + count < 4 && rtpos.x < 4)
	    {
	      if (tetra[rtpos.x][tmp + count + 1] == '#')
		count++;
	      else
		break ;
	    }
	  if (rtpos.y < count + tmp)
	    rtpos.y = count + tmp;
	  rtpos.x++;
	  count = 0;
	}
    }
  else if (rtpos.y < 4 && tetra[rtpos.x][tmp + 1]  && tetra[rtpos.x][tmp] && tetra[rtpos.x][tmp + 1] == '#')
    {
      rtpos.y++;
      return (ft_rtpos2(rtpos, tetra));
    }
  ft_greenstr("rtpos.x = ");
  ft_putnbr(rtpos.x);
  ft_putchar('\n');
  ft_bluestr("rtpos.y = ");
  ft_putnbr(rtpos.y);
  ft_putchar('\n');
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
  while (lpos.x < 4 && tetra[lpos.x][tmp] && tetra[lpos.x + 1][tmp] == '#')
    {
      ft_greenstr("TOUR DU X\n");
      ft_greenstr("lpos.y = ");
      ft_putnbr(lpos.y);
      ft_putchar('\n');
      while (tetra[lpos.x][tmp - count - 1] == '#' && tmp - count >= 0 && lpos.x < 4)
	{
	  ft_bluestr("TOUR DU Y\n");
	  if (tetra[lpos.x][tmp - count - 1] == '#')
	    {
	      ft_putstr("OKOK\n");
	      count++;
	    }
	  else
	    break ;
	}
      if (lpos.y > tmp - count)
	lpos.y = tmp - count;
      lpos.x++;
      count = 0;
      ft_putchar('\n');
    }
  lpos.x = tmp2;
  ft_greenstr("\nlpos.x = ");
  ft_putnbr(lpos.x);
  ft_putchar('\n');
  ft_bluestr("lpos.y = ");
  ft_putnbr(lpos.y);
  ft_putchar('\n');
  return (lpos);
}

/*t_pos	ft_lpos(t_pos lpos, char **tetra)
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
  }*/

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
	      ft_redstr("OKOKOK\n");
              rtpos = ft_rtpos(rtpos, tetra);
              lpos = ft_lpos(lpos, tetra);
	                    ft_putab(tetra);
              str = ft_resize_map(tetra, lpos, rtpos);
	      ft_redstr(str[0]);
	      ft_putchar('\n');
	      ft_redstr(str[1]);
	      ft_putchar('\n');
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
  //  int i = 0;
  char **str;
  str = (char **)malloc(sizeof(char *) + 5);
  str[0] = (char *)malloc(sizeof(char) + 5);
  str[1] = (char *)malloc(sizeof(char) + 5);
  str[2] = (char *)malloc(sizeof(char) + 5);
  str[3] = (char *)malloc(sizeof(char) + 5);
  str[0] = "##..";
  str[1] = ".##.";
  str[2] = "....";
  str[3] = "....";
  str[4] = NULL;

  str = ft_essential(str);
  ft_greenstr("DA RESULT\n");
  ft_bluestr(str[0]);
  ft_putchar('\n');
  ft_bluestr(str[1]);
  ft_putchar('\n');
  /*  while (str[i])
    {
      ft_putstr(str[i]);
            ft_putchar('\n');
      i++;
      }*/
  return (0);
}
