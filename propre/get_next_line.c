/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:30:50 by tiprata           #+#    #+#             */
/*   Updated: 2015/12/14 16:30:52 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
  static char *str = NULL;
  int ret;
  char tmp[BUF_SIZE + 1];
  int stop;
  char *stock;
  int i;
  int j;
  int count;

  count = 0;
  j = 0;
  i = 0;
  stop = 0;
  ret = 0;
  if (str)
    {
      stock = ft_strdup(str);
      free(str);
      str = NULL;
    }
  else
    stock = ft_memalloc(BUF_SIZE + 1);
  while ((ret = read(fd, tmp, BUF_SIZE)))
    {
      tmp[ret] = '\0';
      stop = ft_strchr(tmp, '\n');
      if (stop >= 0)
	{
	  str = ft_strnew(ft_strlen(tmp) - stop);
	  stop++;
	  while (tmp[stop])
	    {
	      if (tmp[stop] == '\n')
		{
		  ft_pinkchar('X');
		  count = stop - 1;
		  stop++;
		}
	      else
		{
		  str[i] = tmp[stop];
		  stop++;
		  i++;
		}
	    }
	  str[i] = '\0';
	  stock = ft_dupnstrcat(stock, tmp, count);//ft_strlen(tmp) - stop);
	  *line = ft_strdup(stock);
	  return (ret);
	}
      else 
	stock = ft_dupstrcat(stock, tmp);
    }
  *line = ft_strdup(stock);
  free(stock);
  stock = NULL;
  return (ret);
}

int	main(int ac, char **av)
{
  int fd;
  int ret;
  char **line;
  int i;
  
  i = 0;
  line = (char **)malloc(sizeof(char *) * 10);
  ret = 0;
  if (ac > 1)
    {
      fd = open(av[1], O_RDONLY);
      while ((ret = get_next_line(fd, &line[i])))
	{
	  ft_bluestr(line[i]);
	  ft_putchar('\n');
	i++;
	}
    }
  line[i] = NULL;
  return (0);
}
