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

  i = 0;
  stop = 0;
  ret = 0;
  if (str)
    {
      ft_bluestr(str);
    }
  if (!(str))
    {
      stock = ft_memalloc(BUF_SIZE + 1);
    }
  else
    {
      stock = ft_strdup(str);
      ft_bluestr(stock);
      free(str);
    }
  while ((ret = read(fd, tmp, BUF_SIZE)))
    {
      tmp[ret] = '\0';
 
      stop = ft_strchr(tmp, '\n');
      if (stop > 0)
	{
	  while (tmp[stop + 1])
	    {
	      str = ft_strnew(ft_strlen(tmp) - stop - 1);	      
	      str[i] = tmp[stop];
	      if (str[i] == '\n')
		ft_putendl("ALERT");
	      ft_pinkchar(str[i]);
	      stop++;
	      i++;
	    }
	  ft_putchar('\n');
	  str[i] = '\0';
	  stock = ft_dupnstrcat(stock, tmp, stop - i);
	  *line = ft_strdup(stock);
	  return (ret);
	 
	}
      else
	stock = ft_dupstrcat(stock, tmp);
    }
  *line = ft_strdup(stock);
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
	i++;
    }
  line[i] = NULL;
  ft_putab(line);
  return (0);
}
