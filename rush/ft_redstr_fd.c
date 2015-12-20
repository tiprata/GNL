#include "get_next_line.h"

void    ft_redstr_fd(char *str, int fd)
{
  ft_putstr_fd("\x1B[31m");
  write(fd, str, ft_strlen(str));
  ft_putstr_fd("\033[0m");
}
