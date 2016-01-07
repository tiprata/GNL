#include "libft.h"

int	main(void)
{
	char **str;
	int i = 0;

	str = ft_strsplit("....\n....\n####\n....\n\n..##\n..##\n....\n....\n\n....\n.###\n..#.\n....\n", '\n');

	while (str[i])
	{
		if (str[i][0] == '\0')
			ft_putstr("|||EMPTY LINE|||\n");
		if (i % 4 == 0 && i != 0)
			ft_putchar('\n');
		ft_putendl(str[i]);
		i++;
	}
	return 0;
}
