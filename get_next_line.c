/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:30:50 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/08 16:31:27 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
  static t_rest s;
  char tmp[BUF_SIZE + 1];
  int stop;
  char *stock = NULL;
  int i;
  int j;
  int count;
  int endof;

  s.indic = 0;
  endof = 0;
  count = 0;
  j = 0;
  i = 0;
  stop = 0;
  if (fd < 0 || line == NULL || *line == NULL)
	  return (-1);
  if (s.indic == 1)
  {
	  *line = ft_strdup("");
	  s.indic = 0;
	  return (s.ret == 0 ? 0 : 1);
  }
  if (s.str != NULL)
  {
      stop = ft_strchr(s.str, '\n');
      if (stop > 0)
	  {
		  if (!(*line = ft_strsub(s.str, 0, stop - 1)))
			  return (-1);
		  while (i != stop + 1)
		  {
			  s.str++;
			  i++;
		  }
		  if (s.str[0] == '\n')
			  s.indic = 1;
		  if (*s.str == '\0')
		  {
			  free(s.tmp);
			  s.str = NULL;
			  s.tmp = NULL;
		  }
//		  ft_putstr("ENDOF NON FIN\n");
		  return (1);
	  }
	  stop = 0;
	  if (!(stock = ft_strdup(s.str)))
		  return (-1);
	  if (s.ret == 0)
	  {
		  *line = ft_strdup(stock);
//		  ft_putstr("ENDOF FILE\n");
		  return (0);
	  }
  }
  else
	  if (!(stock = ft_memalloc(BUF_SIZE + 1)))
		  return (-1);
  while ((s.ret = read(fd, tmp, BUF_SIZE)))
  {
	  tmp[s.ret] = '\0';
	  if (tmp[0] == '\0' && s.ret == 0)
	  {
		  *line = ft_strdup("");
		  return (0);
	  }
	  stop = ft_strchr(tmp, '\n');
	  if (stop >= 0 && s.str == NULL)
	  {
		  if (tmp[stop + 1] == '\n')
		  {
			  s.indic = 1;
		  }
		  if (!(stock = ft_dupnstrcat(stock, tmp, stop - 1)))
			  return (-1);
		  if (!(s.str = ft_strsub(tmp, stop + 1, ft_strlen(tmp) - stop + 1)))
			  return (-1);
		  s.tmp = s.str;
		  if (!(*line = ft_strdup(stock)))
			  return (-1);
//		  ft_putstr("ENDOF NON\n");
		  return (1);
	  }
	  else
	  {
		  if (!(stock = ft_dupstrcat(stock, tmp)))
			  return (-1);
		  free(s.str);
		  s.str = NULL;
	  }
  }
  if (!(*line = ft_strdup(stock)))
	  return (-1);
  if (s.ret == 0)
  {
	  if (*line[0] == '\n')
		  *line = ft_strdup("");
	  return (0);
  }
  free(stock);
  stock = NULL;
  return (1);
}

/*int		main(int ac, char **av)
{
	char **str;
	int i = 0;;
	int ret;
	int count;
	int fd;


	if (ac)
		fd = open(av[1], O_RDONLY);		
	count = 0;
	str = (char **)ft_memalloc(sizeof(char *) * 5);
	while (count != 1)
	{
		ret = get_next_line(fd, &str[i]);
		if (ret == 0)
			count = 1;
		ft_putstr(str[i]);
		ft_putstr("||");
		ft_putchar(str[i][0]);
		ft_putstr("||");
		i++;
		ft_putnbr(i);
	}
	return 0;
	}*/
