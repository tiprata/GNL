#include "get_next_line.h"

void	ft_putab(char **str)
{
  int i;

  i = 0;
  while (str[i])
    {
      ft_putstr("\x1B[32m");
      ft_putendl(str[i]);
      ft_putstr("\033[0m");
      i++;
    }
}
