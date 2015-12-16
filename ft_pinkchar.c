#include "get_next_line.h"

void    ft_pinkchar(char c)
{
  ft_putstr("\x1B[35m");
  write(1, &c, 1);
  ft_putstr("\033[0m");
}
