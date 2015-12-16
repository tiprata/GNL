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

int	get_next_line(int const fd, char **line)
{

}

int	main(int ac, char **av)
{
  int fd;
  int ret;

  ret = 0;
  if (ac > 1)
    {
      fd = open(av[2], O_RDONLY);
      while ((ret = get_next_line(fd, 
    }
  return 0;
}
