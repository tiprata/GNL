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


void	ft_display_matches(int *tab)
{
  int i;
  int matches;

  matches = 0;
  i = 0;
  while (tab[i] != 0)
    {
      while (matches < tab[i])
	{
	  ft_putchar('|');
	  matches++;
	}
      matches = 0;
      i++;
    }
}

int	count_matches(int *tab)
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
int	ft_row(int *tab)
{
  int i;
  int ret;
  int stop;
  char buf[6];
  
  stop = 0;
  ret = 0;
  i = 0;
  ft_display_matches(tab);
  while (stop != 1)
    {
      ret = read(0, buf, 6);
      if (ft_atoi(buf) >= 1 && ft_atoi(buf) <= 3)
	stop = 1;
      ft_redstr_fd("Try again bitch\n", 1);
    }
  TourDuJoueur;
  if (!(count_matches(tab)))
    {
      ft_bluestr("You won ;(\n");
      return (-1);     
      }
  ft_display_matches(tab);
  Tourdelalgo;
  if (!(count_matches(tab)))
    {
      ft_greenstr("Algo WON !\n");
      return (-1);
    }
    ft_row(tab);
    return (0);
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
      buf[ret] = '\0';
      if (ft_atoi(buf) <= 1 && ft_atoi(buf) >= 10000)
	return (0);
      ft_list_push_back(&list, ft_atoi(buf));
    }
  while (list)
    {
      tab[i] = list->i;
      i++;
      list = list->next;
    }
   algo(tab);
  return (1);
}

int	read_from_input(void)
{
  int fd;
  int ret;
  int *tab;
  int i;
  char *buf;
  t_list	*list;

  list = NULL;
  buf = ft_memalloc(6);
  while (ret = get_next_line(0, &buf))
    {
      buf[ret] = '\0';
      if (ft_atoi(buf) <= 1 && ft_atoi(buf) >= 10000)
	return (0);
      ft_list_push_back(&list, ft_atoi(buf));
    }
  while (list)
    {
      tab[i] = list->i;
      i++;
      list = list->next;
    }
  algo(tab);
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

