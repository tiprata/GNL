#include "get_next_line.h"

void    ft_pinkstr(char *str)
{
  ft_putstr("\x1B[35m");
  write(1, str, ft_strlen(str));
  ft_putstr("\033[0m");
}
