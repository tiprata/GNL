#include "get_next_line.h"

void    ft_redstr(char *str)
{
  ft_putstr("\x1B[31m");
  write(1, str, ft_strlen(str));
  ft_putstr("\033[0m");
}
