/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:17:42 by tiprata           #+#    #+#             */
/*   Updated: 2015/12/20 17:17:47 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s)
{
  int             i;

  i = 0;
  while (s[i] != '\0')
    {
      i++;
    }
  return (i);
}

void    ft_list_push_back(t_list **begin_list, int newelem)
{
  t_list *node;
  t_list *tmp;
  if (!(node = (t_list *)malloc(sizeof(t_list))))
    node = NULL;
  node->next = NULL;
  node->i = newelem;
  if (*begin_list == NULL)
    *begin_list = node;
  else
    {
      tmp = *begin_list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = node;
    }
}

void    *ft_memset(void *b, int c, size_t n)
{
  size_t  i;

  i = -1;
  while (++i < n)
    ((char *)b)[i] = (unsigned char)c;
  return (b);
}

void    *ft_memalloc(size_t size)
{
  void    *str;

  if (!(str = (void*)malloc(sizeof(*str) * size)))
    return (NULL);
  str = ft_memset(str, 0, size);
  return (str);
}

void    ft_putstr_fd(char const *s, int fd)
{
  write(fd, s, ft_strlen(s));
}

void    ft_putstr(char const *s)
{
  write(1, s, ft_strlen(s));
}

void    ft_redstr_fd(char *str, int fd)
{
  ft_putstr_fd("\x1B[31m", fd);
  write(fd, str, ft_strlen(str));
  ft_putstr_fd("\033[0m", fd);
}

void    ft_putchar(char c)
{
  write(1, &c, 1);
}

void    ft_bluechar(char c)
{
  ft_putstr("\x1B[36m");
  write(1, &c, 1);
  ft_putstr("\033[0m");
}

void    ft_greenchar(char c)
{
  ft_putstr("\x1B[32m");
  write(1, &c, 1);
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

char    *ft_strchr(const char *s, int c)
{
  char    d;
  int             i;
  char    *s1;

  i = 0;
  d = (char)c;
  s1 = (char *)s;
  while (s1[i] != '\0')
    {
      if (s1[i] == d)
	return (s1 + i);
      i++;
    }
  if (d == '\0')
    return (s1 + i);
  return (0);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
  char    *s3;
  int             i;
  int             j;

  i = -1;
  j = -1;
  if (s1 == NULL && s2 == NULL)
    return (NULL);
  if ((s3 = (char *)malloc(sizeof(char)
			   * (ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
    return (NULL);
  while (s1 != NULL && s1[++j] != '\0')
    s3[++i] = s1[j];
  j = -1;
  while (s2 != NULL && s2[++j] != '\0')
    s3[++i] = s2[j];
  s3[++i] = '\0';
  return (s3);
}

int             get_next_line(int const fd, char **line)
{
  static char           *stock = "";
  int                           ret;
  char                  buf[BUFF_SIZE + 1];
  char                  *line1;
  int                           j;
  int                           y;
  static int                            flag;
  size_t                                v;
  static int            fdbis;


  v = 0;
  y = 0;
  if (stock && fdbis != fd)
    stock = "";
  while ((ret = read(fd, buf, BUFF_SIZE)) != 0 && ret != -1 )
    {
      buf[ret] = '\0';
      stock = ft_strjoin(stock, buf);
      if (stock && ft_strchr(stock, '\n'))
	{
	  y = 0;
	  j = 0;
	  while (stock[y] != '\n')
	    y++;
	  y++;
	  line1 = (char *)malloc(sizeof(char) * y);
	  while (stock[j] != '\n')
	    {
	      line1[j] = stock[j];
	      j++;
	    }
	  line1[j] = '\0';
	  stock = ft_strchr(stock, '\n');
	  //                    if (stock[1] != '\0')
	  //                            flag = 0;
	  stock++;
	  (*line) = line1;
	  y = 0;
	  fdbis = fd;
	  return (1);
	}
    }
  if (ft_strchr(stock, '\n') && flag == 0 )
    {
      while (stock[y] != '\n')
	y++;
      y++;
      j = 0;
      line1 = (char *)malloc(sizeof(char) * y);
      while (stock[j] != '\n')
	{
	  line1[j] = stock[j];
	  j++;
	}
      line1[j] = '\0';
      (*line) = line1;
      while (stock[v] != '\0' && stock[v] != '\n')
	v++;
      if (v == ft_strlen(stock))
	flag = 1;
      stock = ft_strchr(stock, '\n');
      stock++;
      y = 0;
      fdbis = fd;
      return (1);
    }
  /*    if (stock[1] == '\0' && ret == 0)
        {
        while(stock[y] != '\0')
        {
        stock[y] = '\0';
        y++;
        }
        free(stock);
        }*/
  if (ret == -1)
    return (-1);
  if (!(ft_strchr(stock, '\n')) && stock[0] != '\0' && flag == 0)
    {
      j = 0;
      y = 0;
      while (stock[y] != '\0')
	y++;
      y++;
      line1 = (char *)malloc(sizeof(char) * y);
      while (stock[j] != '\0')
	{
	  line1[j] = stock[j];
	  j++;
	}
      line1[j] = '\0';
      (*line) = line1;
      while (stock[v] != '\0' && stock[v] != '\n')
	v++;
      if (v == ft_strlen(stock))
	flag = 1;
      fdbis = fd;
      return (0);
    }
  if (ret == 0)
    {
      (*line) = "";
      fdbis = fd;
      return (0);
    }
  fdbis = fd;
  return (0);
}

int     ft_atoi(const char *str)
{
  size_t  i;
  int             sign;
  int             result;

  result = 0;
  sign = 1;
  i = 0;
  while (str[i] == ' ' || str[i] == '\t' ||
	                         str[i] == '\v' || str[i] == '\r' ||
	 str[i] == '\n' || str[i] == '\f')
    i++;
  if (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	sign = -sign;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      result *= 10;
      result += str[i] - 48;
      i++;
    }
  return (result * sign);
}

void	ft_display_matches(int *tab) // FONCTION OK !
{
  INIT(int, i, 0);
  INIT(int, matches, 0);

  while (tab[i] != 0)
    {      
      while (matches++ < tab[i])
	ft_greenchar('|');
      ft_putchar('\n');
      matches = 0;
      i++;
    }
}

int	count_matches(int *tab) // FONCTION OK 1
{
  int i;
  int rest;

  rest = 0;
  i = 0;
  while (tab[i] != 0)
    {
      rest = rest + tab[i];
      i++;
    }
  return (rest);
}

int             *remove(int i, int *tab)
{
  int j;

  j = 0;
  while (tab[j] != 0)
    j++;
  j--;
  if (tab[j] == 1 && i == 1)
    {
      tab[j] = 0;
      return (tab);
    }
  else if (i < tab[j])
    {
      tab[j] = tab[j] - i;
      return(tab);
    }
  return (NULL);
}

int             *algo(int *tab)
{
  int	i;
  
  i = 0;
  while (tab[i] != 0)
    i++;
  i--;
  if(tab[i] % 4 == 1)
    tab = remove (1, tab);
  else if (tab[i] % 4 == 2)
    tab = remove (1, tab);
  else if (tab[i] % 4 == 3)
    tab = remove (2, tab);
  else if (tab[i] % 4 == 0)
    tab = remove (3, tab);
  return (tab);
}

int	ft_row(int *tab) // Half OK function
{
  int ret;
  int stop;
  char *buf;
  
  stop = 0;
  ret = 0;
  buf = ft_memalloc(6);
  ft_display_matches(tab);
  ft_redstr_fd("Your turn\n", 1);
  while ((ret = get_next_line(0, &buf)))
    {
      if (ft_atoi(buf) >= 1 && ft_atoi(buf) <= 3)
	stop = 1;
      else
	ft_redstr_fd("Try again bitch\n", 1);
      if (stop == 1)
	break ;
    }
  tab = remove(ft_atoi(buf), tab);
  ft_display_matches(tab);
  if (!(count_matches(tab)))
    {
      ft_redstr_fd("Algo WON \n", 1);
      return (-1);     
    }
  ft_redstr_fd("Computer turn\n", 1);
  tab = algo(tab);
  if (!(count_matches(tab)))
    {
      ft_redstr_fd("You won ;(\n", 1);
      return (-1);
    }
      ft_row(tab);
    return (0);
}

int	*fill_array(t_list **begin_list)
{
  t_list *list;
  int *tab;
  int i;

  i = 0;
  list = *begin_list;
  while (list)
    {
      i++;
      list = list->next;
    }
  tab = (int *)malloc(sizeof(int) * i);
  i = 0;
  list = *begin_list;
  while (list)
    {
      tab[i] = list->i;
      i++;
      list = list->next;
    }
  return (tab);  
}
int	read_from_file(char *str)
{
  int fd;
  int ret;
  char *buf;
  int *tab;
  int i;
  t_list *list;
  
  list = NULL;
  i = 0;
  buf = ft_memalloc(6);
  fd = open(str, O_RDONLY);
  while ((ret = get_next_line(fd, &buf)))
    {
      if (ft_atoi(buf) < 1 || ft_atoi(buf) > 10000)
	{
	  ft_redstr_fd("FUCK YOU DEEPLY", 1);
	  return (0);
	}
      ft_list_push_back(&list, ft_atoi(buf));
    }
     tab = fill_array(&list);
   ft_row(tab);
  //algo(tab);
  return (1);
}

int	read_from_input(void)
{
  int fd;
  int ret;
  int *tab;
  char *buf;
  t_list	*list = NULL;

  buf = ft_memalloc(BUF_SIZE);
  fd = 0;
  while ((ret = get_next_line(fd, &buf)))
    {
      if (buf[0] == '\0')
      	break ;
      if (ft_atoi(buf) < 1 || ft_atoi(buf) > 10000)
	return (0);
      ft_list_push_back(&list, ft_atoi(buf));
    }
  tab = fill_array(&list);
  ft_row(tab);
  return (1);
}

int	main(int ac, char **av)
{
  if (ac <= 2)
    {
      if (ac == 2)
	{
	  if (!(read_from_file(av[1])))
	    {
	      ft_redstr_fd("An error occured in the text file", 3);
	      return (0);
	    }
	}
      else
	{
	  if (!(read_from_input()))
	    {
	      ft_redstr_fd("An error occured in the map input. Try again", 3);
	      return (0);
	    }
	}
    }
  else
    {
      ft_redstr_fd("An error occured. Try with a single file, asshole.", 3);
      return (0);
    }
}

